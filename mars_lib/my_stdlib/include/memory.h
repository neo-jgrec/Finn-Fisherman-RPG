/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** memory
*/

#ifndef MEMORY_H_
    #define MEMORY_H_

    #include <stdlib.h>

    /**
    * @brief my_memset - fills the first n bytes
    * of the memory area pointed to by s with the constant byte c
    *
    * @param dest pointer to the memory area to be filled
    * @param src value to be set
    * @param n number of bytes to be set to the value
    * @return void* - copy of the pointer dest
    */
    void *my_memcpy(void *dest, const void *src, size_t n);

    /**
    * @brief my_memset - fills the first n bytes of
    * the memory area pointed to by s with the constant byte c
    *
    * @param s pointer to the memory area to be filled
    * @param c value to be set
    * @param n number of bytes to be set to the value
    * @return void* - pointer to the memory area s
    */
    void *my_memset(void *s, int c, size_t n);

    /**
    * @brief my_realloc - reallocates a memory block using malloc and free
    *
    * @param ptr pointer to the memory block to be reallocated
    * @param size new size for the memory block
    * @return void* pointer to the reallocated memory block
    */
    void *my_realloc(void *ptr, size_t size);

    /**
    * @brief my_calloc - allocates memory for an
    * array of nmemb (number of members) elements of size bytes each
    * and returns a pointer to the allocated memory. The memory is set to zero.
    *
    * @param nmemb number of elements
    * @param size size of each element
    * @return void* - pointer to the allocated memory
    */
    void *my_calloc(size_t nmemb, size_t size);

    /**
    * @brief my_memmove - copies n bytes from memory
    * area src to memory area dest
    *
    * @param dest area to copy to
    * @param src area to copy from
    * @param n number of bytes to copy
    * @return void* - copy of the pointer dest
    */
    void *my_memmove(void *dest, const void *src, size_t n);

#endif /* !MEMORY_H_ */
