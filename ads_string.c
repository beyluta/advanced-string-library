#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ads_string.h"

ads_string *ads_create(const char *const src)
{
    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = strlen(src);
    temp->buffer = (char *)malloc(sizeof(char) * (temp->size + 1));
    for (size_t i = 0; i < temp->size; i++)
    {
        memcpy(temp->buffer, src, temp->size);
    }
    temp->buffer[temp->size] = '\0';

    return temp;
}

void ads_destroy(ads_string *src)
{
    free(src->buffer);
    free(src);
    src = NULL;
}

char ads_char_at(ads_string *src, size_t pos)
{
    return src->buffer[pos % (src->size + 1)];
}

int ads_char_code_at(ads_string *src, size_t pos)
{
    return ads_char_at(src, pos) - '0';
}

int ads_is_equal(ads_string *src, ads_string *target)
{
    return strcmp(src->buffer, target->buffer);
}

int ads_ends_with(ads_string *src, ads_string *target)
{
    if (src->size <= 0 || target->size <= 0)
    {
        return EXIT_FAILURE;
    }

    for (size_t i = target->size, j = 0; i > 0; i--)
    {
        if (src->buffer[(src->size - 1) - j++] != target->buffer[i - 1])
        {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int ads_includes(ads_string *src, ads_string *target)
{
    for (size_t i = 0, j = 0; i < src->size; i++)
    {
        if (src->buffer[i] != target->buffer[j] && j > 0)
        {
            return EXIT_FAILURE;
        }
        else if (src->buffer[i] == target->buffer[j] && j >= target->size - 1)
        {
            return EXIT_SUCCESS;
        }
        else if (src->buffer[i] == target->buffer[j])
        {
            j++;
        }
    }

    return EXIT_FAILURE;
}

int ads_index_of(ads_string *src, ads_string *target)
{
    if (ads_includes(src, target) == EXIT_FAILURE)
    {
        return EXIT_OOB;
    }

    for (size_t i = 0, j = 0; i < src->size; i++)
    {
        if (src->buffer[i] != target->buffer[j] && j > 0)
        {
            return EXIT_OOB;
        }
        else if (src->buffer[i] == target->buffer[j] && j >= target->size - 1)
        {
            return i - target->size + 1;
        }
        else if (src->buffer[i] == target->buffer[j])
        {
            j++;
        }
    }

    return EXIT_OOB;
}

ads_string *ads_concat(ads_string *src, ads_string *target)
{
    size_t pos = 0;
    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = src->size + target->size;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    memcpy(temp->buffer, src->buffer, src->size);
    for (size_t i = 0; i < target->size; i++)
    {
        temp->buffer[i + src->size] = target->buffer[i];
    }
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string *ads_trim_start(ads_string *src)
{
    size_t start = 0;
    for (size_t i = 0; i < src->size; i++)
    {
        if (src->buffer[i] != WHITESPACE_CHAR)
        {
            start = i;
            break;
        }
    }

    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = src->size - start;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    for (size_t i = start; i < src->size; i++)
    {
        temp->buffer[i - start] = src->buffer[i];
    }
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string *ads_trim_end(ads_string *src)
{
    size_t end = src->size;
    for (int i = end - 1; i > -1; i--)
    {
        if (src->buffer[i] != WHITESPACE_CHAR)
        {
            end = i;
            break;
        }
    }

    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = end + 1;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    memcpy(temp->buffer, src->buffer, temp->size);
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string *ads_trim(ads_string *src)
{
    ads_string *temp_start = ads_trim_start(src);
    ads_string *temp_end = ads_trim_end(temp_start);
    ads_destroy(temp_start);
    return temp_end;
}

ads_string *ads_to_lowercase(ads_string *src)
{
    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = src->size;
    temp->buffer = (char *)malloc(sizeof(temp->size));

    for (size_t i = 0; i < src->size; i++)
    {
        temp->buffer[i] = tolower(src->buffer[i]);
    }
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string *ads_to_uppercase(ads_string *src)
{
    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = src->size;
    temp->buffer = (char *)malloc(sizeof(temp->size));

    for (size_t i = 0; i < src->size; i++)
    {
        temp->buffer[i] = toupper(src->buffer[i]);
    }
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string *ads_replace(ads_string *src, ads_string *query, ads_string *target)
{
    if (ads_includes(src, query) == EXIT_FAILURE)
    {
        return NULL;
    }

    size_t start = ads_index_of(src, query);
    size_t end = start + query->size;

    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = start;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    memcpy(temp->buffer, src->buffer, start);
    temp->buffer[temp->size] = '\0';

    ads_string *temp1 = ads_concat(temp, target);
    ads_destroy(temp);

    temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = src->size - end + 1;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    for (size_t i = 0; i < temp->size; i++)
    {
        temp->buffer[i] = src->buffer[i + end];
    }
    temp->buffer[temp->size - 1] = '\0';

    ads_string *concat = ads_concat(temp1, temp);
    ads_destroy(temp);
    ads_destroy(temp1);
    return concat;
}

ads_string *ads_reverse(ads_string *src)
{
    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = src->size;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    for (size_t i = 1; i < src->size + 1; i++)
    {
        temp->buffer[i - 1] = src->buffer[src->size - i];
    }
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string *ads_slice(ads_string *src, const size_t start, const size_t end)
{
    if (end < start && end > src->size + 1)
    {
        return NULL;
    }

    const size_t between = end - start + 1;
    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = src->size - between;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    for (size_t i = 0, j = 0; i < src->size; i++)
    {
        if (i < start || i > end)
        {
            temp->buffer[i - j] = src->buffer[i];
        }
        else
        {
            j++;
        }
    }
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string *ads_copy(ads_string *src, const size_t start, const size_t end)
{
    ads_string *temp = (ads_string *)malloc(sizeof(ads_string));
    temp->size = end - start + 1;
    temp->buffer = (char *)malloc(sizeof(char) * temp->size);
    for (size_t i = 0, j = 0; i < src->size; i++)
    {
        if (i >= start && i <= end)
        {
            temp->buffer[j++] = src->buffer[i];
        }
    }
    temp->buffer[temp->size] = '\0';
    return temp;
}

ads_string **ads_split(ads_string *src, const char target, size_t *len)
{
    *len = 1;
    for (size_t i = 0; i < src->size; i++)
    {
        if (src->buffer[i] == target)
        {
            *len = *len + 1;
        }
    }

    ads_string **objects = (ads_string **)malloc(sizeof(ads_string *) * (*len));
    for (size_t i = 0, j = 0, k = 0; i < src->size + 1; i++)
    {
        if (src->buffer[i] == target || i >= src->size)
        {
            objects[k++] = ads_copy(src, j, i - 1);
            j = i + 1;
        }
    }

    return objects;
}