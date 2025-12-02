/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:54 by mbenedet          #+#    #+#             */
/*   Updated: 2025/12/02 17:54:14 by mbenedet         ###   ########.fr       */
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
	int			newline_index;
	size_t		i;
	ssize_t		bytes_read;

	//Delimeter condition
	buffer = malloc(BUFFER_SIZE + 1); //why? It's initialisation --> allocate to initalise
	if (!buffer)
		return (NULL);
	
	//implement read function
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';

	// Append buffer to stash from get_next_line_utils function strjoin
	stash = ft_strjoin_gnl(stash, buffer);
	i = 0;
	while(buffer[i] != '\n')
	{
		stash[i] = buffer[i];
		newline_index = find_newline(stash);
		if(newline_index >= '\0')
			break;
		i++;
	}
	stash[i] = '\0';
	line = stash;
	
	i = stash[newline_index + 1];
	while (stash != NULL && newline_index == '\0')
	{
		leftover_data = malloc(leftover_data + 1);
		leftover_data[i] = new_stash[i];
		i++;
		if(leftover_data[i] == '\0')
			new_stash = leftover_data;
		i++;
	}
	free(stash);
	line = new_stash;
	
	return (line);
}

int main(void)
{
	int fd;
	char *text = "text.txt";
	char *line;
	
	fd = open("test.txt", O_RDONLY);
	//error checking
	if (fd == -1)
	{
		perror("Error opening file");
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
 Join function:

 find length of stash

find length of buffer

allocate new memory

copy stash

copy buffer after stash

free(old_stash)
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

/* 
Applied learning from fundamentals:
1/2. This means I need a while loop counting the line till newline: should this be done in the utils inside the strlen function or the gnl main file inside the gnl main function.
Could it be something on the line of:
 while(stash[i] != '\n')
	{
		stash[i] = stash[i + buffer[i];
	}?
3. line = malloc(ft_strlen_gnl + 1);?
4. I fixed it already inside the strlen gnl function:

	if (string == NULL)
    	return (0);

5. stash = NULL to initialise prior to append/call.
6. 
Var 1 = stash
Var 2 = line return + stash + string left until the next/final  newline.

7. Provide an example of copy function using different methods eg. index vs temp pointer

8. Unclear what you mean

9. 


USEFUL INFO
Step 1 — Start with stash

if stash has no newline → read() again

if stash has newline → extraction begins immediately

Step 2 — Join stash + buffer

(stash grows)

Step 3 — Find newline in stash

If not found → read again
If found → extract line

Step 4 — Extract line

Return a newly allocated string up to newline

Step 5 — Update stash

Replace stash with leftover after newline
*/

/* 
Iteration 1:

	FAULTY
	new_stash = ft_strjoin_gnl(stash, buffer);	
	// Find newline and extract it
	line = malloc(ft_strlen_gnl + 1);
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
	

*/