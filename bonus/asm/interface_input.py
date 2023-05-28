import customtkinter as tk

tk.set_appearance_mode("dark")
tk.set_default_color_theme("green")

def is_instruction(instruction):
    if (instruction == "live" or instruction == "zjmp" or instruction == "aff"):
        return True
    if (instruction == "fork" or instruction == "lfork"):
        return True
    if (instruction == "ld" or instruction == "lld"):
        return True
    if (instruction == "st" or instruction == "sti"):
        return True
    if (instruction == "add" or instruction == "sub"):
        return True
    if (instruction == "and" or instruction == "or" or instruction == "xor"):
        return True
    if (instruction == "ldi" or instruction == "lldi"):
        return True
    return False

def enter_parametre(f, main_frame, the_instruction):

    def direct(f):
        direct_param = tk.CTkEntry(master=main_frame, placeholder_text="direct (%)")
        direct_param.pack(pady=10, padx=10)
        result = direct_param.get()
        if result and result[0] == "%":
            f.write(result)
            print(result + " ")

    def register(f):
        register_param = tk.CTkEntry(master=main_frame, placeholder_text="register (r)")
        register_param.pack(pady=10, padx=10)
        result = register_param.get()
        if result and result[0] == "r":
            f.write(result)
            print(result + " ")

    def inddirec(f):
        inddirec_param = tk.CTkEntry(master=main_frame, placeholder_text="direct (%) or indirect")
        inddirec_param.pack(pady=10, padx=10)
        result = inddirec_param.get()
        if result and result[0] == "%":
            f.write(result)
            print(result + " ")

    def regindirec(f):
        regindirec_param = tk.CTkEntry(master=main_frame, placeholder_text="register (r) or indirect")
        regindirec_param.pack(pady=10, padx=10)
        result = regindirec_param.get()
        if result and (result[0] == "r" or result[0] != "%"):
            f.write(result)
            print(result + " ")

    def regdirec(f):
        regdirec_param = tk.CTkEntry(master=main_frame, placeholder_text="register (r) or direct (%)")
        regdirec_param.pack(pady=10, padx=10)
        result = regdirec_param.get()
        if result and (result[0] == "r" or result[0] == "%"):
            f.write(result)
            print(result + " ")

    def any(f):
        any_param = tk.CTkEntry(master=main_frame, placeholder_text="register (r), indirect or direct (%)")
        any_param.pack(pady=10, padx=10)
        f.write(any_param.get())
        print(any_param.get() + " ")

    def singles(f):
        direct(f)
        f.write("\n")

    def aff(f):
        register(f)
        f.write("\n")

    def arithmetics(f):
        register(f)
        f.write(", ")
        register(f)
        f.write(", ")
        register(f)
        f.write("\n")

    def bitwise(f):
        any(f)
        f.write(", ")
        any(f)
        f.write(", ")
        register(f)
        f.write("\n")

    def load(f):
        inddirec(f)
        f.write(", ")
        register(f)
        f.write("\n")

    def st(f):
        register(f)
        f.write(", ")
        regindirec(f)
        f.write("\n")

    def loadindex(f):
        any(f)
        f.write(", ")
        regdirec(f)
        f.write(", ")
        register(f)
        f.write("\n")

    def sti(f):
        register(f)
        f.write(", ")
        any(f)
        f.write(", ")
        regdirec(f)
        f.write("\n")

    if (the_instruction[-1] == ":"):
        print(the_instruction)
        f.write(the_instruction + "\n")
    match the_instruction:
        case "live":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=singles(f))
            subbutton.pack(pady=5, padx=5)
        case "ld":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=load(f))
            subbutton.pack(pady=5, padx=5)
        case "st":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=st(f))
            subbutton.pack(pady=5, padx=5)
        case "add":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=arithmetics(f))
            subbutton.pack(pady=5, padx=5)
        case "sub":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=arithmetics(f))
            subbutton.pack(pady=5, padx=5)
        case "and":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=bitwise(f))
            subbutton.pack(pady=5, padx=5)
        case "or":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=bitwise(f))
            subbutton.pack(pady=5, padx=5)
        case "xor":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=bitwise(f))
            subbutton.pack(pady=5, padx=5)
        case "zjmp":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=singles(f))
            subbutton.pack(pady=5, padx=5)
        case "ldi":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=loadindex(f))
            subbutton.pack(pady=5, padx=5)
        case "sti":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=sti(f))
            subbutton.pack(pady=5, padx=5)
        case "fork":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=singles(f))
            subbutton.pack(pady=5, padx=5)
        case "lld":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=load(f))
            subbutton.pack(pady=5, padx=5)
        case "lldi":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=loadindex(f))
            subbutton.pack(pady=5, padx=5)
        case "lfork":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=singles(f))
            subbutton.pack(pady=5, padx=5)
        case "aff":
            subbutton = tk.CTkButton(master=main_frame, text="Enter", command=aff(f))
            subbutton.pack(pady=5, padx=5)
        case _:
            if (the_instruction[-1] != ":"):
                print("Invalid Instruction or label (add : for label)")

def start_body(f):
    asm = tk.CTk()
    asm.geometry("900x900")
    asm.title("ASM Interface")

    main_frame = tk.CTkScrollableFrame(master=asm)
    main_frame.pack(pady=50, padx=50, fill="both", expand=True)

    label = tk.CTkLabel(master=main_frame, justify=tk.LEFT, text="BODY")
    label.pack(pady=10, padx=10)

    instruction = tk.CTkEntry(master=main_frame, placeholder_text="instruction")
    instruction.pack(pady=10, padx=10)

    def enter_instruction():
        the_instruction = instruction.get()
        if is_instruction(the_instruction) == True:
            f.write(the_instruction + "\t")
            print(the_instruction + "\t")

        if (the_instruction[-1] == ":" or is_instruction(the_instruction) == True):
            textlab = tk.CTkLabel(master=main_frame, justify=tk.LEFT, text=the_instruction)
            textlab.pack(pady=10, padx=10)

        add_param = tk.CTkButton(master=main_frame, text="Enter Parametre", command=enter_parametre(f, main_frame, the_instruction))
        add_param.pack(pady=5, padx=5)

    asm_button = tk.CTkButton(master=main_frame, text="Submit", command=enter_instruction)
    asm_button.pack(pady=10, padx=10)

    asm.mainloop()

def start_header():
    root = tk.CTk()
    root.geometry("900x900")
    root.title("ASM Interface")

    frame = tk.CTkFrame(master=root)
    frame.pack(pady=50, padx=50, fill="both", expand=True)

    file_entry = tk.CTkEntry(master=frame, placeholder_text="Champion (filename)")
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
