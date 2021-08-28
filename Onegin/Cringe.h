/*!
 * \file Cringe.h
 * \author Gekata
 * \brief Dont try to open it(it doesnt work)
 */

#pragma once
#pragma warning(disable : 4996)

const int std_strlen = 2000;
const int const_str_count = 15;
struct Line {
    int line_len;
    char* p;
};

struct LineNode {
    Line* line;
    LineNode* next;
};

void clearList (LineNode* node) {
    LineNode* cur_node = NULL;
    while (node != NULL) {
        cur_node = node->next;
        free (node);
        node = cur_node;
    }
    return;
}

LineNode* mergeList (LineNode* first, LineNode* second){
    if (first == NULL){
        return second;
    }

    if (second == NULL) {
        return first;
    }

    LineNode* begin = first;
    while(first->next != NULL){
        first = first->next;
    }

    first->next = second;
    return begin;
}

int get_prior (Line* inp, int ind, int is_reversed) {
    if (!is_reversed) {

        if (ind >= inp->line_len) {
            return 0;
        }
        return inp->p[ind] + 1;

    } else {

        if (ind >= inp->line_len) {
            return 0;
        }
        return inp->p[inp->line_len - ind - 1] + 1;

    }
}

LineNode* sortStringsRadix (LineNode* lines, int strings_cnt, int str_pos, int max_str_pos, int is_reversed) {
    if (str_pos > max_str_pos){
        return lines;
    }
    
    int* buff = ( int* ) calloc (257, sizeof (int));
    LineNode** buckets = (LineNode**) calloc (257, sizeof (LineNode*));
    
    LineNode* cursor  = lines;
    LineNode* temp;
    while (cursor != NULL) 
    {
        int prior = get_prior (cursor->line, str_pos, is_reversed);

        if(buckets[prior] == NULL){
            buckets[prior] = cursor;
            cursor = cursor->next;

        } else {
            temp = cursor->next;
            cursor->next = buckets[prior];
            cursor = temp;

        }
    }



    for(int it = 0; it < 257; ++it){
        printf ("%d %d\n", *(buckets[it]->line->p));
    }
    /*int count = 0;
    int temp;
    for (int it = 0; it < 257; ++it) {
        temp = buff[it];
        buff[it] = count;
        count += temp;
    }

    printf ("%d %d\n", 0, buff[0]);
    for (int it = 90; it < 130; ++it) {
        printf ("%d %d\n", it, buff[it]);
    }
    for (int str_num = 0; str_num < strings_cnt; ++str_num) {
        int n_pos = buff[get_prior (lines + str_num, str_pos, is_reversed)];
        printf ("%d %c\n", n_pos, *((lines + str_num)->p));
        temp_lines[n_pos] = lines[str_num];
        ++buff[get_prior (lines + str_num, str_pos, is_reversed)];
    }

    for (int i = 0; i < strings_cnt; ++i) {
        printf ("%s", temp_lines[i].p);
    }


    std::swap (temp_lines, lines);
    for (int it = 0; it < 257; ++it) {
        buff[it] = 0;
    }*/
    printf ("");
    //free (temp_lines);
    return;
};


void readOnegin (FILE* inp, LineNode** lines, int* lines_cnt) {
    *lines_cnt = 0;
    lines = ( LineNode** ) calloc (1, sizeof (LineNode*));
    LineNode* cursor = (*lines);
    char* buff = ( char* ) calloc (std_strlen, sizeof (char));
    while (!feof (inp)) {
        fgets (buff, 200, inp);
        *cursor->line = {};
        cursor->line->line_len= strlen (buff) - 1;
        cursor->line->p = (char*) calloc ( (*lines)[*lines_cnt].line->line_len, sizeof(char));
        memcpy ( cursor->line->p, buff, sizeof(char) * (cursor->line->line_len) );
        cursor->next = (LineNode*) calloc (1, sizeof(LineNode));
        ++(*lines_cnt);
        free(buff);
        buff = ( char* ) calloc (std_strlen, sizeof (char));
    }
    --(*lines_cnt);
    free (buff);


    return;

}