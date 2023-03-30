/*
** EPITECH PROJECT, 2023
** array
** File description:
** array
*/

#ifndef ARRAY_H_
    #define ARRAY_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <unistd.h>

    /**
    * @brief Create a array object
    *
    * @param nb_elements int
    * @return the list in a void**
    */
    void** create_array(int nb_elements);

    /**
    * @brief Get the array size object
    *
    * @param array void**
    * @return int
    */
    int get_array_size(void **array);

    /**
    * @brief Add an element at the head of the array
    *
    * @param array void**
    * @param element void*
    * @return void**
    */
    void **add_element_head(void **array, void *element);

    /**
    * @brief Add an element at the tail of the array
    *
    * @param array void**
    * @param element void*
    * @return void**
    */
    void **add_element_tail(void **array, void *element);

    /**
    * @brief Remove an element at index
    *
    * @param array void**
    * @param index int
    * @return void**
    */
    void **remove_element(void **array, int index);

    /**
    * @brief Print an array
    *
    * @param array void**
    * @param print_function void (*print_function)(void*)
    */
    void print_array(void **array, void (*print_function)(void*));

    /**
    * @brief Check if an element is present in the array
    *
    * @param array void **
    * @param element void *
    * @param compare_function bool (*compare_function)(void *, void *)
    * @return true / false
    */
    bool is_element_present(void **array, void *element,
    bool (*compare_function)(void *, void *));

    /**
    * @brief Reverse an array
    *
    * @param array void**
    * @return void** The reversed array
    */
    void **reverse_array(void **array);

    /**
    * @brief Copy an array
    *
    * @param array void**
    * @return void** The copied array
    */
    void **copy_array(void **array);

    /**
    * @brief Get the element index object
    *
    * @param array void**
    * @param element void*
    * @param compare_function bool (*compare_function)(void *, void *)
    * @return int
    */
    int get_element_index(void **array, void *element,
    bool (*compare_function)(void *, void *));

    /**
    * @brief Get the element object
    *
    * @param array void**
    * @param index int
    * @return void*
    */
    void *get_element(void **array, int index);

    /**
    * @brief Insert an element at a specific index
    *
    * @param array void**
    * @param element void*
    * @param index int
    * @return void**
    */
    void **insert_element_at_index(void **array, void *element, int index);

    /**
    * @brief Remove an element at a specific index
    *
    * @param array void**
    * @param index int
    * @return void**
    */
    void **remove_at_index(void **array, int index);

#endif /* !ARRAY_H_ */
