/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:54 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/02 11:20:40 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

//joining stash + buffer - rename as join_stash_buffer

char *get_next_line(int fd)
{
	static char *stash;
	char 		*buffer;
	char		*new_stash;
	char		*line;
	char		*leftover_data;
	size_t		i;
	ssize_t		bytes_read;

	//Delimeter condition
	buffer = malloc(BUFFER_SIZE + 1); //why? It's initialisation --> allocate to initalise
	if (!buffer)
		return (NULL);
	
	//implement read function
	bytes_read = read(fd, buffer, BUFFER_SIZE);

	// Append buffer to stash from get_next_line_utils function strjoin
	new_stash = ft_strjoin_gnl(stash, buffer);
	
	// Find newline and extract it
	line = malloc(new_stash[i] + 1);
	while (line != 0 && --buffer != 0)
	{
		if((*line++ = *buffer++) == 0)
			break;
	} while(--buffer != 0);
	
	
	//update stash to include leftover memory
	while(!stash)
		stash[i] = newline[i] - stash[i]--;
	free (buffer)
	return (line);
	
}

int main(void)
{
	int fd;
	char *text = "text.txt";
	char *line;
	
	fd = open("test.txt", O_RDWR | O_CREAT, 0666); // O_RDWR (read/write) and O_CREAT (create if it doesn't exist).
	//error checking
	if (fd == -1)
	{
		perror("Error opening file")
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf(line);
		free(line);
	}
}

/* char    *get_next_line(int fd)
{
	static char *stash;
	char        *buffer;
	ssize_t     bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	// 1. read into buffer
	bytes_read = read(fd, buffer, BUFFER_SIZE);

	// 2. append buffer to stash
	stash = join(stash, buffer);

	// 3. find newline and extract line
	line = extract(stash);

	// 4. update stash
	stash = update(stash);

	free(buffer);
	return (line);
}
 */

/* 
int open  (const char* path, int flags [, int mode ])
{
	
}

ssize_t read(int fildes, void *buf, size_t nbyte)
{
	
}

char *get_next_line(int fd)
{
	//Open function
	// Read function
	static char stash[BUFFER_SIZE +1];
	
	size_t len_of_buffer;

	stash = malloc(len_of_buffer + 1);
	
} */


/* 
Inside get_next_line():

Use leftover stash if exists

While no newline inside stash:

allocate buffer

read() into buffer

append buffer to stash

stop if read returns 0 or -1

Extract line from stash

Update stash to leftover

Return extracted line
-----------------------------------------------------------------------
 get_next_line returns:
👉 The next line INCLUDING the newline if it exists
 👉 NULL when no more lines or on error
A “line” means:
everything up to \n OR


all remaining text when EOF is reached.

 If no newline is found and read() returns 0 (EOF), then:
stash might still contain data


that data (even without newline) is returned as the last line


then next call returns NULL


Actual behavior:
You read until EOF


If stash is not empty → return it as the last line


Then GNL ends

------------------------------------------------------------
⛔ Stash is NEVER reallocated in-place.

You always:

allocate a NEW stash,

copy old stash + buffer,

free old stash.

--------------------------------------------------------
BUFFER_SIZE does NOT eliminate leftover data.
Only newline position does.

------------------------------------------------------------
leftover is the data after the newline
✔ Even large BUFFER_SIZE cannot avoid leftover.
❌ Only newline position determines leftover creation.m
----------------------------------------
BUFFER_SIZE controls: how many bytes per read.
Stash controls: how many bytes accumulated.
Leftover exists if: newline splits data into two parts.

Stash + buffer combo: Code

new_stash = ft_strjoin(stash, buffer)
free(stash)
stash = new_stash

*/