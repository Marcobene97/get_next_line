*This project has been created as part of the 42 curriculum by <mbenedet>.*

# 1. Project Description - Get Next Line

- The purpose of the project is to read and return a line from a file descriptor until the end of the file.
If there are multiple lines, the function will return each line until the end of the file.
- The use is predominantly in systems programming and application development: file parsing, memory maangement, streams handling.

The project folder is organised as it follows:
- get_next_line.c: contains the main get next line function along with 3 helper functions.
- get_next_line_utils.c: holds 5 helpers which set the foundation for the string handling in the main .c file. Common 42 functions are found in this document: strdup, strlen, strchr, strlcpy, strlcat.

1. ft_strchr: Searches for the first occurrence of a character in a string.
2. ft_strlen_gnl: Counts the length of the file until the NULL terminator. 
3. ft_strlcpy: Copies a string from src to dst with size limit, guaranteeing null-termination.
4. ft_strlcat: Appends src to the end of dst with size limit, guaranteeing null-termination.
5. ft_strdup: creates a copy of a string in dynamically allocated memory.

- get_next_line.h: Contains function prototypes, macro definitions (`BUFFER_SIZE`), and necessary library includes (`<unistd.h>`, `<stdlib.h>`, `<fcntl.h>`, `<stdio.h>`) required for the project. It serves as the interface between the main function and utility functions, ensuring proper compilation and linking.

- Makefile: Optional to use. It's built to ease testing during production. 

Instructions:
To run the project there are several options:
- uncomment the main and create a test.txt file if not present with the desired specifics, then cc -Wall -Wextra -Werror -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c
- cc get_next_line.c get_next_line_utils.c, specifying the file name inside the project folder
- Use Makefile

Resources:
1. https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
2. https://medium.com/@lannur-s/gnl-c3cff1ee552b
3. https://man7.org/linux/man-pages/man2/read.2.html
4. https://github.com/xicodomingues/francinette


Additional Section:
explanation and justification of the algorithm selected 
The project

A README.md file must be provided at the root of your Git repository. Its purpose
is to allow anyone unfamiliar with the project (peers, staff, recruiters, etc.) to quickly
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