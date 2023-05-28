import customtkinter as tk

tk.set_appearance_mode("dark")
tk.set_default_color_theme("green")

INSTRUCTIONS = [
    [
        "live", 1, [["T_DIR"]]
    ],
    [
        "ld", 2, [["T_DIR", "T_IND"], ["T_REG"]]
    ],
    [
        "st", 2, [["T_REG"], ["T_DIR", "T_IND"]]
    ],
    [
        "add", 3, [["T_REG"], ["T_REG"], ["T_REG"]]
    ],
    [
        "sub", 3, [["T_REG"], ["T_REG"], ["T_REG"]]],
    [
        "and", 3, [["T_REG", "T_DIR", "T_IND"], [
            "T_REG", "T_IND", "T_DIR"], ["T_REG"]]
    ],
    [
        "or", 3, [["T_REG", "T_DIR", "T_IND"], [
            "T_REG", "T_IND", "T_DIR"], ["T_REG"]]
    ],
    [
        "xor", 3, [["T_REG", "T_DIR", "T_IND"], [
            "T_REG", "T_IND", "T_DIR"], ["T_REG"]]
    ],
    [
        "zjmp", 1, [["T_DIR"]]
    ],
    [
        "ldi", 3, [["T_REG", "T_DIR", "T_IND"], [
            "T_REG", "T_DIR"], ["T_REG"]]
    ],
    [
        "fork", 1, [["T_DIR"]]
    ],
    [
        "lld", 2, [["T_DIR", "T_IND"], ["T_REG"]]
    ],
    [
        "lldi", 3, [["T_REG", "T_DIR", "T_IND"], [
            "T_REG", "T_DIR"], ["T_REG"]]
    ],
    [
        "lfork", 1, [["T_DIR"]]
    ],
    [
        "aff", 1, [["T_REG"]]
    ],
    [
        "sti", 3, [["T_REG"], ["T_REG", "T_DIR", "T_IND"], [
            "T_DIR", "T_REG"]]
    ]
]

ARGUMENT_TYPES_MESSAGES = {
    "T_REG": "Register (r?)",
    "T_DIR": "Direct (%?)",
    "T_IND": "Indirect (?)"
}


def is_instruction(instruction):
    for i in INSTRUCTIONS:
        if instruction == i[0]:
            return i
    return 0

def contains(array, value):
    for i in array:
        if i == value:
            return True
    return False

def verify_parameter_value(value, type):
    if (value[0] == "r" and contains(type, "T_REG")):
        return True
    if (value[0] == "%" and contains(type, "T_DIR")):
        return True
    if (value[0] != "%" and value[0] != "r" and contains(type, "T_IND")):
        return True
    return False

def set_parameter_entry(instruction, main_frame, instruction_index):
    string = ""
    for i in instruction[2][instruction_index]:
        string += ARGUMENT_TYPES_MESSAGES[i]
        string += " "
    return tk.CTkEntry(master=main_frame, placeholder_text=string)

def get_instrucion_params(f, instruction, main_frame):
    params = []
    for i in range(instruction[1]):
        params.append(set_parameter_entry(instruction, main_frame, i))
    for i in range(instruction[1]):
        params[i].pack(pady=10, padx=10)

    def on_save_params():
        for i in range(instruction[1]):
            value = params[i].get()
            print("value => {}", value)
            if (verify_parameter_value(value, instruction[2][i]) == False):
                print("Error: parameter value not valid")
                return
            f.write(value + "\t")

    save_params = tk.CTkButton(
        master=main_frame, text="Save Params", command=on_save_params)
    save_params.pack(pady=10, padx=10)



def start_body(f):
    asm = tk.CTk()
    asm.geometry("900x900")
    asm.title("ASM Interface")

    main_frame = tk.CTkScrollableFrame(master=asm)
    main_frame.pack(pady=50, padx=50, fill="both", expand=True)

    label = tk.CTkLabel(master=main_frame, justify=tk.LEFT, text="BODY")
    label.pack(pady=10, padx=10)

    instruction = tk.CTkEntry(
        master=main_frame, placeholder_text="instruction")
    instruction.pack(pady=10, padx=10)

    def enter_instruction():
        f.write("\n")
        the_instruction = instruction.get()
        print("Instruction: " + the_instruction)
        inst = is_instruction(the_instruction)
        if inst == 0:
            print("Error: instruction not found")
            return
        if inst != 0:
            f.write(the_instruction + "\t")
            print(the_instruction + "\t")

        if (the_instruction[-1] == ":" or inst != 0):
            textlab = tk.CTkLabel(
                master=main_frame, justify=tk.LEFT, text=the_instruction)
            textlab.pack(pady=10, padx=10)
        get_instrucion_params(f, inst, main_frame)

    asm_button = tk.CTkButton(
        master=main_frame, text="Submit", command=enter_instruction)

    asm_button.pack(pady=10, padx=10)

    asm.mainloop()


def start_header():
    root = tk.CTk()
    root.geometry("900x900")
    root.title("ASM Interface")

    frame = tk.CTkFrame(master=root)
    frame.pack(pady=50, padx=50, fill="both", expand=True)


    file_entry = tk.CTkEntry(
        master=frame, placeholder_text="Champion (filename)")

    file_entry.pack(pady=50, padx=10)

    label = tk.CTkLabel(master=frame, justify=tk.LEFT, text="HEADER")
    label.pack(pady=10, padx=10)

    header_name = tk.CTkEntry(master=frame, placeholder_text="name")
    header_name.pack(pady=10, padx=10)

    comment_name = tk.CTkEntry(master=frame, placeholder_text="comment")
    comment_name.pack(pady=10, padx=10)

    def enter_header():
        print("Name: " + header_name.get())
        print("Comment: " + comment_name.get())

        filename = file_entry.get() + ".s"
        f = open(filename, "w")
        f.write("\t.name \"" + header_name.get() + "\"\n")
        f.write("\t.comment \"" + comment_name.get() + "\"\n\n")
        start_body(f)

    button = tk.CTkButton(master=frame, text="Submit", command=enter_header)
    button.pack(pady=10, padx=10)

    print("Creating file...")
    root.mainloop()



start_header()
print("File created!")
