<div align="center">

*This project has been created as part of the 42 curriculum by bramalho*

<!-- Animated Header -->
<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Gear.png" width="80"/>

# 🔧 pipex - Recreating the Shell Pipe

<img src="https://img.shields.io/badge/Score-125%2F125-success?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Circle-2-00BABC?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white"/>
<img src="https://img.shields.io/badge/Concepts-Pipes%20%7C%20Fork%20%7C%20Exec-FF6B6B?style=for-the-badge&logoColor=white"/>
<img src="https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge&logo=42&logoColor=white"/>

**A faithful reimplementation of the UNIX shell pipe mechanism — from `fork()` to `execve()`**

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="600"/>

</div>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Light%20Bulb.png" width="25"/> Description

**pipex** is a deep dive into how the UNIX shell actually works under the hood. The project challenges you to replicate the behaviour of the **`|` (pipe) operator** entirely in C — reading from an input file, piping output between commands, and writing the final result to an output file.

The equivalent shell command:
```bash
cat infile | grep "hello" > outfile
```
becomes:
```bash
./pipex infile "grep hello" "cat" outfile
```

This project teaches you the **core pillars of UNIX process management**:
- 🔀 **Pipes** — inter-process communication via `pipe()`
- 🍴 **Forking** — spawning child processes with `fork()`
- ⚡ **Execution** — replacing processes with `execve()`
- 📁 **File descriptors** — redirection with `dup2()`
- 🗺️ **PATH resolution** — finding executables in the environment

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Travel%20and%20places/Rocket.png" width="25"/> Features

<table>
<tr>
<td width="50%">

### 🎯 Mandatory Features
- ✅ **Two-command pipeline** — `infile | cmd1 | cmd2 > outfile`
- ✅ **PATH resolution** — searches `$PATH` for executables
- ✅ **Absolute path support** — `/usr/bin/grep` style commands
- ✅ **File descriptor redirection** — `dup2()` for stdin/stdout
- ✅ **Error handling** — missing files, unknown commands
- ✅ **Clean memory management** — zero leaks (Valgrind approved)

</td>
<td width="50%">

### 🌟 Bonus Features (Implemented!)
- ✅ **Multiple command pipeline** — unlimited chained pipes
- ✅ **here_doc support** — heredoc-style input (`<< LIMITER`)
- ✅ **Append mode** — `>>` outfile behaviour with here_doc
- ✅ **Iterative child spawning** — loop-based pipeline execution
- ✅ **GNL integration** — get_next_line for here_doc reading
- ✅ **Robust fd cleanup** — all descriptors properly closed

</td>
</tr>
</table>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Gear.png" width="25"/> Technical Stack

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Make](https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=cmake&logoColor=white)
![POSIX](https://img.shields.io/badge/POSIX-API-3B4D50?style=for-the-badge&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-00599C?style=for-the-badge&logo=gnu&logoColor=white)
![Valgrind](https://img.shields.io/badge/Valgrind-3B4D50?style=for-the-badge&logo=gnu&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-42-00BABC?style=for-the-badge)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/File%20Folder.png" width="25"/> Project Structure

```
pipex/
├── Makefile                    # Build system (mandatory + bonus)
├── includes/
│   └── pipex.h                 # Main header — structs, defines, prototypes
├── src/                        # Shared source (mandatory & bonus)
│   ├── pipex.c                 # Mandatory main — two-command pipeline
│   ├── pipex_bonus.c           # Bonus main — N-command pipeline + here_doc
│   ├── parsing.c               # PATH extraction & command path resolution
│   ├── execute.c               # execve wrapper & binary lookup (get_cmd)
│   ├── utils.c                 # open_file (read/write/append) & msg_error
│   ├── cleanup.c               # close_fds & parent_free
│   └── here_doc.c              # Heredoc input reader (bonus)
├── libft/                      # Your Libft library
├── ft_printf/                  # Your ft_printf library
├── GNL/                        # Get Next Line (bonus — here_doc reader)
└── README.md                   # This documentation
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Hammer%20and%20Wrench.png" width="25"/> Instructions

### Prerequisites
- GCC compiler with C99 support
- Make build system
- UNIX/Linux environment
- Valgrind (optional, for memory testing)

### Compilation

```bash
# Clone the repository
git clone <your-repository-url>
cd pipex

# Compile mandatory (two-command pipeline)
make

# Compile bonus (N-command pipeline + here_doc)
make bonus

# Clean object files
make clean

# Full clean (remove executables)
make fclean

# Rebuild everything
make re
```

### Usage

#### Mandatory — Two-Command Pipeline

```bash
# Basic pipe: read infile, run cmd1, pipe to cmd2, write to outfile
./pipex infile "cmd1" "cmd2" outfile

# Real-world examples:
./pipex infile "grep hello" "wc -l" outfile
./pipex infile "cat" "sort" outfile
./pipex infile "tr a-z A-Z" "rev" outfile

# With absolute paths:
./pipex infile "/usr/bin/grep hello" "/usr/bin/wc -l" outfile
```

#### Bonus — Multiple Chained Pipes

```bash
# Unlimited pipe chain: infile | cmd1 | cmd2 | ... | cmdN > outfile
./pipex infile "cmd1" "cmd2" "cmd3" outfile

# Example: grep → sort → uniq → count
./pipex infile "grep error" "sort" "uniq" "wc -l" outfile
```

#### Bonus — Here Document

```bash
# here_doc LIMITER cmd1 cmd2 ... outfile
# Reads stdin until LIMITER is entered, pipes through commands, appends to outfile
./pipex here_doc EOF "cat" "wc -l" outfile

# Interactive session:
# $ ./pipex here_doc STOP "grep hello" "wc -l" results.txt
# hello world        ← typed by user
# hello there        ← typed by user
# goodbye            ← typed by user
# STOP               ← limiter reached → pipeline executes
# $ cat results.txt
# 2
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Memo.png" width="25"/> How It Works

### 🔀 Mandatory Flow — Two Commands

```
┌──────────┐   dup2(infile→stdin)    ┌─────────┐
│  infile  │ ──────────────────────► │  cmd1   │ (child 1)
└──────────┘                         └────┬────┘
                                          │ stdout → pipe[1]
                                          ▼
                                     ┌─────────┐   pipe[0] → stdin
                                     │  cmd2   │ (child 2)
                                     └────┬────┘
                                          │ dup2(stdout→outfile)
                                          ▼
                                     ┌──────────┐
                                     │ outfile  │
                                     └──────────┘

Parent: fork() child1 → fork() child2 → waitpid() both → cleanup
```

### 🔀 Bonus Flow — N Commands (Iterative)

```
┌──────────┐     ┌───────┐  pipe  ┌───────┐  pipe  ┌───────┐     ┌──────────┐
│  infile  │ ──► │ cmd1  │ ─────► │ cmd2  │ ─────► │ cmd3  │ ──► │ outfile  │
└──────────┘     └───────┘        └───────┘        └───────┘     └──────────┘
                  child            child            last child
                  (loop i=0)       (loop i=1)       (exec in parent)
```

The bonus uses a **loop-based spawning pattern**: each iteration creates a child that executes the current command, the parent inherits the pipe's read end as its new stdin, and the loop advances. The **last command** is executed directly in the parent (no extra fork).

### 📝 Here Doc Flow

```
                  ┌──────────────────────┐
  User types  ──► │  read_input() child  │  (reads stdin via GNL)
  lines until     │  writes to pipe[1]   │
  LIMITER hit     └──────────┬───────────┘
                             │
                        pipe[0] → parent stdin
                             │
                             ▼
                  ┌──────────────────────┐
                  │  Pipeline execution  │  (same as bonus N-cmd flow)
                  │  appends to outfile  │
                  └──────────────────────┘
```

### 🔍 Key Design Decisions

| Decision | Why |
|---|---|
| Shared `t_pipex` struct | Single source of truth for fds, paths, args — avoids global variables |
| `mode` parameter in `open_file()` | Handles read (`0`), write/truncate (`1`), and append (`2`) cleanly |
| `get_cmd()` with `ft_strchr('/')` | Detects absolute paths instantly — skips PATH search |
| Last cmd exec'd in parent (bonus) | Matches real shell behaviour; avoids one unnecessary fork |
| `close_fds()` before `exec` in children | Prevents fd leaks across execve boundaries |

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Magnifying%20Glass%20Tilted%20Left.png" width="25"/> Testing & Validation

### Memory Testing

```bash
# Mandatory
valgrind --leak-check=full --show-leak-kinds=all ./pipex infile "cat" "wc -l" outfile

# Bonus
valgrind --leak-check=full --show-leak-kinds=all ./pipex infile "grep x" "sort" "uniq" outfile

# Expected: "All heap blocks were freed -- no leaks are possible"
```

### Functional Tests

```bash
# ── Mandatory ──────────────────────────────────────────────────

# Compare pipex vs real shell
./pipex infile "grep hello" "wc -l" out_pipex
cat infile | grep hello | wc -l > out_shell
diff out_pipex out_shell              # Should be empty

# Nonexistent infile (should error to stderr)
./pipex nonexistent "cat" "wc" outfile

# Unknown command (should error, exit 127)
./pipex infile "fakecmd" "cat" outfile

# Empty infile
touch empty && ./pipex empty "cat" "wc -l" outfile

# ── Bonus ───────────────────────────────────────────────────────

# Triple pipe
./pipex infile "cat" "sort" "uniq" outfile

# Five-stage pipeline
./pipex infile "cat" "tr a-z A-Z" "sort" "uniq" "wc -l" outfile

# Here doc — basic
./pipex here_doc EOF "cat" "wc -l" outfile
# (type lines, then EOF)

# Here doc — append (run twice, outfile should grow)
./pipex here_doc STOP "cat" outfile
./pipex here_doc STOP "cat" outfile
wc -l outfile   # Should be double
```

### Edge Cases Checklist

- ✅ Infile does not exist → error on stderr
- ✅ Outfile does not exist → created automatically
- ✅ Command not in PATH → "command not found" on stderr
- ✅ Absolute path command → works without PATH lookup
- ✅ Empty infile → pipeline runs, outfile is empty/zero
- ✅ here_doc limiter on first line → empty input to pipeline
- ✅ Outfile append (here_doc) → content accumulates across runs
- ✅ All fds closed in children before execve → no descriptor leaks

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Pushpin.png" width="25"/> Common Challenges & Solutions

<table>
<tr>
<td width="50%">

### ❌ Common Issues
- Pipe data lost / outfile empty
- Segfault after fork
- "Command not found" for valid commands
- here_doc hangs waiting for input
- Memory leaks in child processes
- Zombie processes after execution

</td>
<td width="50%">

### ✅ Solutions
- Close unused pipe ends in both parent & children
- Check `fork()` return — handle `-1` error case
- Verify PATH parsing; test with absolute paths first
- Ensure limiter comparison strips the newline (GNL)
- Children that `execve` don't leak — but failed execs must `exit()`
- Always `waitpid()` for every child in the parent

</td>
</tr>
</table>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Light%20Bulb.png" width="25"/> The Norm Compliance

This project strictly follows the 42 School Norm:
- ✅ Maximum 25 lines per function
- ✅ Maximum 80 columns per line
- ✅ Maximum 5 functions per file
- ✅ No forbidden keywords (`printf`, `exit` in main, etc.)
- ✅ Proper variable declarations (top of scope only)
- ✅ No global variables
- ✅ Bonus code in dedicated files (`pipex_bonus.c`, `here_doc.c`)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Books.png" width="25"/> Resources

### 📚 Classic References
- [Pipe System Call — man 2 pipe](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [Fork System Call — man 2 fork](https://man7.org/linux/man-pages/man2/fork.2.html)
- [Execve System Call — man 2 execve](https://man7.org/linux/man-pages/man2/execve.2.html)
- [Dup2 System Call — man 2 dup2](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [UNIX File Descriptors Explained](https://en.wikipedia.org/wiki/File_descriptor)
- [Here Document — Bash Manual](https://www.gnu.org/software/bash/manual/html_node/Redirections.html)
- [42 Norminette](https://github.com/42School/norminette)

### 🤖 AI Usage Description

**AI tools were used for the following specific tasks:**

#### 1. **Process Flow & Architecture Research**
- **Tool**: Claude for understanding pipe/fork/exec interaction patterns
- **Usage**: Researching how real shells chain processes, fd inheritance across fork, and the correct order of dup2/close calls

#### 2. **Code Review and Debugging**
- **Usage**: Verifying fd cleanup order, here_doc limiter matching, and bonus loop spawn correctness — all code was written, understood, and tested independently

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Mobile%20Phone.png" width="25"/> Contact

**Bruno Gomes** - 42 Porto Student

[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:brunodrcgomes@gmail.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/meetbrunogomes/)
[![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)](https://profile.intra.42.fr/users/bramalho)

---

<div align="center">

### <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Chart%20Increasing.png" width="25"/> Project Statistics

```c
typedef struct s_project_stats {
    char    *project;           // "pipex"
    int     lines_of_code;      // ~350 lines
    int     functions;          // 15+ functions
    int     source_files;       // 7 .c files (+ libft/printf/GNL)
    int     memory_leaks;       // 0 (Valgrind approved!)
    int     norm_errors;        // 0 (Norminette passing)
    char    *circle;            // "Circle 2"
    char    *key_concepts;      // "pipe | fork | execve | dup2 | here_doc"
} t_pipex_stats;
```

---

### 💡 Pro Tips

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Nerd%20Face.png" width="20"/> **Close unused pipe ends first** — Forgetting this is the #1 cause of hanging pipelines

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Food/Hot%20Beverage.png" width="20"/> **Test with `diff` against real shell** — Your output must be byte-identical

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Star-Struck.png" width="20"/> **Master the mandatory before touching bonus** — The loop spawn pattern builds directly on the two-fork pattern

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Smiling%20Face%20with%20Sunglasses.png" width="20"/> **Use `strace` to debug fd issues** — See exactly which system calls fire and when

</div>

---

<div align="center">

### 🏆 Achievement Unlocked!

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Activities/Trophy.png" width="60"/>

**UNIX Pipeline Master**

*"Because shell pipes are just fork() and dup2() wearing a trench coat."*

<br>

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer"/>

</div>
