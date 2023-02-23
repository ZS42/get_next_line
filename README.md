# get_next_line-stack<img width="1175" alt="Get_next_line" src="https://user-images.githubusercontent.com/82111543/218945693-17947968-f50d-45d5-a08b-12a3226d9c44.png">


In this project, we learned about file descriptors. They help us to recognize which file is being opened or read. Get_next_line is supposed to be able to read and return up to and including a new line. It reads into a buffer and after returning up to and including the new line saves the rest to be appended at the beginning of the next line. It will continue reading till the end of the file.  Some new functions we got to use here were read, malloc, and free.
Calloc vs malloc. Can use malloc to allocate one block of memory but should use calloc to allocate several equal contiguous blocks of memory in the bonus as it will fill in the allocated space with zeroes preventing errors as in the bonus we have to handle multiple fds.
Free frees memory allocated by malloc, calloc or realloc .
This was also our first time of using valgrind to make sure freeing was done properly and there were no leaks.
