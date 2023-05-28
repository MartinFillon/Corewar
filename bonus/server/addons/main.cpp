/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** read the header of a core file
*/

#include <fstream>
#include <napi.h>
#include <stdint.h>

#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048
#define COREWAR_EXEC_MAGIC 0xea83f3 /* why not */

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

int32_t swap_endian(int32_t val)
{
    return (
        ((val & 0x000000FF) << 24) | ((val & 0x0000FF00) << 8) |
        ((val & 0x00FF0000) >> 8) | ((val & 0xFF000000) >> 24)
    );
}

Napi::Object readHeader(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() != 1 || !info[0].IsString()) {
        Napi::TypeError::New(env, "String expected")
            .ThrowAsJavaScriptException();
    }

    Napi::String fileName = info[0].As<Napi::String>();
    Napi::Object returnValue = Napi::Object::New(env);

    header_t header;
    memset(&header, 0, sizeof(header_t));

    std::ifstream fileStream(fileName.ToString(), std::ifstream::binary);

    if (!fileStream.is_open()) {
        Napi::TypeError::New(env, "File not found: " + std::string(fileName))
            .ThrowAsJavaScriptException();
    }

    fileStream.read(reinterpret_cast<char *>(&header), sizeof(header_t));

    returnValue.Set("name", header.prog_name);
    returnValue.Set("comment", header.comment);
    returnValue.Set("progSize", swap_endian(header.prog_size));

    return returnValue;
}

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    exports.Set("readHeader", Napi::Function::New(env, &readHeader));

    return exports;
}

NODE_API_MODULE(corewar_read_header, InitAll)
