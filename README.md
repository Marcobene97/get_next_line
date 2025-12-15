*This project has been created as part of the 42 curriculum by <mbenedet>.*

# 1. Project Description - Get Next Line

- The purpose of the project is to read and return a line from a file descriptor until the end of the file.
If there are multiple lines, the function will return each line until the end of the file.
- The use is predominantly in systems programming and application development: file parsing, memory management, streams handling.

The project folder is organised as it follows:
- get_next_line.c: contains the main get next line function along with 3 helper functions.
- get_next_line_utils.c: holds 5 helpers which set the foundation for the string handling in the main .c file. Common 42 functions are found in this document: strdup, strlen, strchr, strlcpy, strlcat.

1. ft_strchr: Searches for the first occurrence of a character in a string.
2. ft_strlen_gnl: Counts the length of the file until the NULL terminator. 
3. ft_strlcpy: Copies a string from src to dst with size limit, guaranteeing null-termination.
4. ft_strlcat: Appends src to the end of dst with size limit, guaranteeing null-termination.
5. ft_strdup: creates a copy of a string in dynamically allocated memory.

- get_next_line.h: Contains function prototypes, macro definitions (`BUFFER_SIZE`), and necessary library includes (`<unistd.h>`, `<stdlib.h>`, `<fcntl.h>`, `<stdio.h>`) required for the project. It serves as the interface between the main function and utility functions, ensuring proper compilation and linking. 

# 2.Instructions:
To run the project there are several options:
- uncomment the main and create a test.txt file - if not present - with the desired specifics, then cc -Wall -Wextra -Werror -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c
- cc get_next_line.c get_next_line_utils.c, specifying the file name inside the project folder

# 3.Resources:

1. https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line
2. https://medium.com/@lannur-s/gnl-c3cff1ee552b
3. https://man7.org/linux/man-pages/man2/read.2.html
4. https://github.com/xicodomingues/francinette
5. https://man7.org/linux/man-pages/man3/free.3.html 


# 4. Additional Section: explanation and justification of the algorithm selected 
From a functional perspective project stands on a logic tree hierarchy.
The utils file collects the most basic function upon which the main .c file is built upon.
From an operational perspective the project has been built choosing a static buffer to preserve data and leftover across function calls. This includes ancillary functions acting as a necessary stepping stone: file reading, delimiter checks and line counting with specific rules.
Once a newline is found the program returns that specific line and continues the loop until the end of function is reached. 
In the meantime, each time the memory is allocated, the buffer determines the how many bytes read are transfered into the stash as well as how large is the leftover remaining.
It begins from the most basic functions to measure the length of the string inside the file descriptor, return a specific subset of the desired string up to dealing with string manipulation. 
The classification of algorithms used involves the newline search, the static variable behaviour, the management of the buffer and the overall processing stream.