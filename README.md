*This project has been created as part of the 42 curriculum by smeza-ro.*

## Description

**get_next_line** is a C project that implements a function capable of reading a file line by line from any file descriptor. The primary goal is to create a robust function that:

- Reads content from a file descriptor (fd) efficiently
- Returns one complete line at a time (including the newline character when present)
- Handles multiple file descriptors simultaneously through static variables
- Manages memory efficiently and handles edge cases (empty files, files without newlines, etc.)

This project reinforces fundamental C programming concepts including static variables, dynamic memory allocation, string manipulation, and file I/O operations.

### Execution

The `get_next_line` function is designed to be used as part of a larger project. To use it in your code:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // Print the line
        free(line);           // Free allocated memory
    }
    close(fd);
    return (0);
}
```

### Compilation Flags

Compile with custom `BUFFER_SIZE`:

```bash
gcc -D BUFFER_SIZE=1024 -o program get_next_line.c get_next_line_utils.c main.c
```

The default `BUFFER_SIZE` is 42 bytes.

## Algorithm Explanation and Justification

### Overview

The `get_next_line` function uses a **static buffer stashing approach** to efficiently read and manage file content:

### Key Components

1. **Static Stash Buffer**: A static string variable maintains leftover content from the previous read operation. This allows the function to:
   - Avoid re-reading already processed data
   - Handle multiple file descriptors independently (in bonus version)
   - Provide continuity across multiple function calls
Readme Requirements
A README.md file must be provided at the root of your Git repository. Its purpose is
to allow anyone unfamiliar with the project (peers, staff, recruiters, etc.) to quickly
understand what the project is about, how to run it, and where to find more information
on the topic.
The README.md must include at least:
• The very first line must be italicized and read: This project has been created as part
of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]].
• A “Description” section that clearly presents the project, including its goal and a
brief overview.
• An “Instructions” section containing any relevant information about compilation,
installation, and/or execution.
• A “Resources” section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the project.
➠ Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.).
Any required additions will be explicitly listed below.
• A detailed explanation and justification of the algorithm selected for this project
must also be included.
2. **Reading Strategy**:
   - Read chunks of data (defined by `BUFFER_SIZE`) from the file descriptor
   - Accumulate data in the stash using `ft_strjoin()`
   - Stop reading when a newline character is encountered or EOF is reached

3. **Line Extraction**:
   - Search for the first newline character using `ft_strchr()`
   - Extract the complete line (including the newline) using `ft_strtrim()`
   - Preserve remaining content for the next function call using `ft_stash()`

4. **Memory Management**:
   - Dynamic allocation for buffers and strings
   - Proper cleanup with `ft_free()` on error
   - User responsible for freeing returned lines

### Why This Approach?

- **Efficiency**: Minimizes system calls by reading in chunks rather than character-by-character
- **Simplicity**: Static variable maintains state without exposing complexity to the caller
- **Flexibility**: `BUFFER_SIZE` can be adjusted at compile time for different use cases
- **Robustness**: Handles edge cases like files without trailing newlines, empty files, and large lines

### Time Complexity

- Per line read: O(n) where n is the line length
- Total I/O operations: O(n/BUFFER_SIZE) where n is total file size

### Space Complexity

- O(BUFFER_SIZE) for the read buffer
- O(line_length) for the returned line
- Static storage for the stash

## Resources

### Documentation & References

- **POSIX File I/O**: [read(2) man page](https://man7.org/linux/man-pages/man2/read.2.html)
- **C Dynamic Memory**: [malloc(3) and free(3) man pages](https://man7.org/linux/man-pages/man3/malloc.3.html)
- **String Manipulation**: [Standard C Library String Functions](https://man7.org/linux/man-pages/man3/string.3.html)
- **42 School Curriculum**: [42 Common Core Projects](https://github.com/42School)

### AI Usage

AI assistance was utilized for:
- **Code Review**: Verifying memory safety and resource cleanup
- **Edge Case Testing**: Identifying potential failure scenarios (empty files, missing newlines, large buffers)
- **Documentation**: Generating clear, structured README content and algorithm explanations
- **Optimization Suggestions**: Recommending efficient string concatenation and buffer management patterns

No code was generated by AI; all implementation is original and manually written, with AI providing guidance and review support throughout development.

## Project Files

- `get_next_line.h` - Main header file
- `get_next_line.c` - Core function implementation
- `get_next_line_utils.c` - Utility functions (string operations)
- `get_next_line_bonus.h` - Bonus header (multiple fd support)
- `get_next_line_bonus.c` - Bonus main function
- `get_next_line_utils_bonus.c` - Bonus utility functions

## Status

✅ Mandatory part complete  
✅ Bonus part complete  
✅ All edge cases handled
