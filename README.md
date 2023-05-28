# Corewar

The **Corewar** project is a game in which several programs called "**Champions**" will fight to stay the last one
alive. Corewar is actually a computer simulation in which processors will share memory to run on.

## How does it work?

The project is based on a **virtual machine** in which the champions will fight for memory by all possible
means in order to win, the last champion being able to signal that he is alive wins the game. In other words,
the last champion to execute the "**live**" instruction is declared winner.

## Getting Started

### Installation

Clone this repository.

### Quickstart

Build the project:

```bash
make
```

### Usage

Run the assembler:
```txt
./asm/asm file_name[.s]
```

Run the virtual machine:
```txt
./corewar/corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```

### BONUS

**Web visualizer**: [https://corewar.vercel.app/](https://corewar.vercel.app/)

You can self-host the server and the client.

Server:
```bash
cd bonus/server
docker compose build
docker compose up -d
```

Client:
```bash
cd bonus/client
npm install

# copy .env.example to .env and set the SOCKET_URL to the url of the server
npm run build

# to run the client
npm run preview -- --port 3000
```

## Our team ❤️

Developers
| [<img src="https://avatars.githubusercontent.com/u/114916607?v=4" width=85><br><sub>Antoine Lê</sub>](https://github.com/n0v46027) | [<img src="https://avatars.githubusercontent.com/u/109749395?v=4" width=85><br><sub>Lou Onezime</sub>](https://github.com/louonezime) | [<img src="https://avatars.githubusercontent.com/u/114775771?v=4" width=85><br><sub>Martin Fillon</sub>](https://github.com/MartinFillon) | [<img src="https://avatars.githubusercontent.com/u/51637671?v=4" width=85><br><sub>Martin Saldinger</sub>](https://github.com/LeTamanoir) |
| :--------------------------------------------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------------------------------------------------: | :---------------------------------------------------------------------------------------------------------------------------------------: | :---------------------------------------------------------------------------------------------------------------------------------------: |
