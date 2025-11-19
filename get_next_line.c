/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenedet <mbenedet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:52:54 by mbenedet          #+#    #+#             */
/*   Updated: 2025/11/19 21:05:14 by mbenedet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

int open  (const char* path, int flags [, int mode ])
{
	path = /Desktop/Work/GNLfd;
	
}

ssize_t read(int fildes, void *buf, size_t nbyte)
{
	
}

char *get_next_line(int fd)
{
	//Open function
	// Read function
	const char *stash;
	size_t len_of_buffer;

	stash = malloc(len_of_buffer + 1);
	
}

int main(void)
{
	
}

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

*/