#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void delete_space(char* str)
{
    if (str == NULL)
        return;
    char* skim = str;
    char* dest = str;
    while (*skim != '\n' && *skim != '\0')
    {
        if (*skim != ' ')
        {
            *dest = *skim;
            dest++;
        }
        skim++;
    }
    *dest = '\0';
}

void split_elements(char* no_space_str, char elements[][120], int* elem_count)
{
    *elem_count = 0;
    int i = 0;
    int len = strlen(no_space_str);
    while (i < len)
    {
        if ((no_space_str[i] >= 'a' && no_space_str[i] <= 'z') ||
            (no_space_str[i] >= 'A' && no_space_str[i] <= 'Z'))
        {
            int j = 0;
            while (i < len && ((no_space_str[i] >= 'a' && no_space_str[i] <= 'z') ||
                (no_space_str[i] >= 'A' && no_space_str[i] <= 'Z') ||
                (no_space_str[i] >= '0' && no_space_str[i] <= '9')))
            {
                elements[*elem_count][j++] = no_space_str[i++];
            }
            elements[*elem_count][j] = '\0';
            (*elem_count)++;
        }
        else if ((no_space_str[i] >= '0' && no_space_str[i] <= '9') ||
            no_space_str[i] == '.' ||
            (no_space_str[i] == '-' && (i == 0 || strchr("+-*/^=(", no_space_str[i - 1]) != NULL)))
        {
            int j = 0;
            if (no_space_str[i] == '-') 
            {
                elements[*elem_count][j++] = no_space_str[i++];
            }
            while (i < len && ((no_space_str[i] >= '0' && no_space_str[i] <= '9') || no_space_str[i] == '.'))
            {
                elements[*elem_count][j++] = no_space_str[i++];
            }
            elements[*elem_count][j] = '\0';
            (*elem_count)++;
        }
        else if (strchr("+-*/^()=;", no_space_str[i]) != NULL)
        {
            elements[*elem_count][0] = no_space_str[i++];
            elements[*elem_count][1] = '\0';
            (*elem_count)++;
        }
        else
            i++;
    }
}

int push_op(char op_stack[], int* top, char op)
{
    op_stack[(*top)++] = op;
    return 0;
}

int pop_op(char op_stack[], int* top, char* op) 
{
    if (*top <= 0)
    {
        printf("Error: empty stack\n");
        return 1;
    }
    *op = op_stack[--(*top)];
    return 0;
}

int get_top_op(char op_stack[], int top, char* op)
{
    if (top <= 0)
        return 1;
    *op = op_stack[top - 1];
    return 0;
}

int get_priority(char op)
{
    switch (op)
    {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    case '(': return 0;
    default: return -1;
    }
}

void infix_to_postfix(char elements[][120], int elem_count, char postfix[][120], int* postfix_len)
{
    *postfix_len = 0; 
    char op_stack[120]; 
    int op_top = 0;     

    for (int i = 0; i < elem_count; i++)
    {
        char* elem = elements[i];
        if ((elem[0] >= '0' && elem[0] <= '9') ||
            (elem[0] == '-' && elem[1] >= '0' ) || 
            ((elem[0] >= 'a' && elem[0] <= 'z') || (elem[0] >= 'A' && elem[0] <= 'Z')))
        {
            strcpy(postfix[*postfix_len], elem);
            (*postfix_len)++;
        }
        else if (strcmp(elem, "(") == 0)
        {
            push_op(op_stack, &op_top, '(');
        }
        else if (strcmp(elem, ")") == 0)
        {
            char top_op;
            while (get_top_op(op_stack, op_top, &top_op) == 0 && top_op != '(')
            {
                pop_op(op_stack, &op_top, &top_op);
                postfix[*postfix_len][0] = top_op;
                postfix[*postfix_len][1] = '\0';
                (*postfix_len)++;
            }
            if (get_top_op(op_stack, op_top, &top_op) == 0 && top_op == '(')
            {
                pop_op(op_stack, &op_top, &top_op);
            }
        }
        else if (strchr("+-*/^", elem[0]) != NULL) 
        {
            char current_op = elem[0];
            char top_op;
            while (get_top_op(op_stack, op_top, &top_op) == 0)
            {
                if (get_priority(current_op) <= get_priority(top_op))
                {
                    pop_op(op_stack, &op_top, &top_op);
                    postfix[*postfix_len][0] = top_op;
                    postfix[*postfix_len][1] = '\0';
                    (*postfix_len)++;
                }
                else 
                    break;
            }
            push_op(op_stack, &op_top, current_op); 
        }
        else if (strcmp(elem, "=") == 0 || strcmp(elem, ";") == 0)
        {
            continue;
        }
    }
    char top_op;
    while (get_top_op(op_stack, op_top, &top_op) == 0)
    {
        pop_op(op_stack, &op_top, &top_op);
        postfix[*postfix_len][0] = top_op;
        postfix[*postfix_len][1] = '\0';
        (*postfix_len)++;
    }
}
//variables control
#define MAX_VARS 20       
#define VAR_NAME_LEN 15  
char vars[MAX_VARS][VAR_NAME_LEN] = { 0 }; 
double var_values[MAX_VARS] = { 0.0 };   
int var_count = 0;                    

double find_var(char* var_name) 
{
    for (int i = 0; i < var_count; i++) 
    {
        if (strcmp(vars[i], var_name) == 0) 
        {
            return var_values[i];
        }
    }
    return 0.0; 
}

int update_var(char* var_name, double value) 
{
    if (strlen(var_name) > 10) return 1;
    for (int i = 0; i < var_count; i++) 
    {
        if (strcmp(vars[i], var_name) == 0) 
        {
            var_values[i] = value;
            return 0;
        }
    }
    if (var_count < MAX_VARS) 
    {
        strcpy(vars[var_count], var_name);
        var_values[var_count] = value;
        var_count++;
        return 0;
    }
    return 1; 
}
//stack of calculations
#define STACK_SIZE 120
int push_num_stack(double stack[], int* top, double value) 
{
    if (*top >= STACK_SIZE) 
    {
        printf("Error: stack overflow\n");
        return 1;
    }
    stack[(*top)++] = value;
    return 0;
}

int pop_num_stack(double stack[], int* top, double* value) 
{
    if (*top <= 0) 
    {
        printf("Error: empty stack\n");
        return 1;
    }
    *value = stack[--(*top)];
    return 0;
}

int calculate_postfix(char postfix[][120], int postfix_len, double* result) 
{
    double num_stack[STACK_SIZE] = { 0.0 };
    int num_top = 0;                     

    for (int i = 0; i < postfix_len; i++) 
    {
        char* elem = postfix[i];
        double val1 = 0.0, val2 = 0.0, res = 0.0;
        if ((elem[0] >= '0' && elem[0] <= '9') || (elem[0] == '-' && (elem[1] >= '0' || elem[1] == '.')))
        {
            push_num_stack(num_stack, &num_top, atof(elem));
        }
        else if ((elem[0] >= 'a' && elem[0] <= 'z') || (elem[0] >= 'A' && elem[0] <= 'Z')) 
        {
            double var_val = find_var(elem);
            push_num_stack(num_stack, &num_top, var_val);
        }
        else if (strchr("+-*/^", elem[0]) != NULL) 
        {
            if (pop_num_stack(num_stack, &num_top, &val2) != 0) return 1;
            if (pop_num_stack(num_stack, &num_top, &val1) != 0) return 1;
            switch (elem[0]) 
            {
            case '+': res = val1 + val2; break;
            case '-': res = val1 - val2; break;
            case '*': res = val1 * val2; break;
            case '/':
                if (val2 == 0.0) 
                { 
                    printf("Error: invalid calculation\n");
                    return 1;
                }
                res = val1 / val2;
                break;
            case '^': res = pow(val1, val2); break;
            default:
                printf("Error: unknown operation\n");
                return 1;
            }
            push_num_stack(num_stack, &num_top, res);
        }
        else 
        {
            continue;
        }
    }
    if (num_top != 1) 
    {
        printf("Error: wrong output\n");
        return 1;
    }
    *result = num_stack[num_top - 1];
    return 0;
}

int main()
{
    FILE* commands = fopen("commands.txt", "r");
    if (commands == NULL)
    {
        perror("Failed to open file");
        return 1;
    }
    char elements[120][120] = { 0 };    
    char postfix[120][120] = { 0 };     
    int elem_count = 0;                 
    int postfix_len = 0;                
    int line_num = 0;                   
    char str[120] = { '0' };
    double calc_result = 0.0;           
    int has_semicolon = 0;              
    while (fgets(str, 120, commands) != NULL)
    {
        line_num++;
        elem_count = 0;
        postfix_len = 0;
        calc_result = 0.0;
        has_semicolon = 0;
        memset(elements, 0, sizeof(elements));
        memset(postfix, 0, sizeof(postfix));
        delete_space(str);
        if (strlen(str) == 0) 
        {
            continue;
        }
        split_elements(str, elements, &elem_count);
        for (int k = 0; k < elem_count; k++)
        {
            if (strcmp(elements[k], ";") == 0)
            {
                has_semicolon = 1;
            }
        }
        char var_name[VAR_NAME_LEN] = { 0 };
        int expr_start_idx = -1; 
        for (int k = 0; k < elem_count; k++) 
        {
            if (strcmp(elements[k], "=") == 0) 
            {
                strcpy(var_name, elements[k - 1]); 
                expr_start_idx = k + 1;            
                break;
            }
        }
        char expr_elements[120][120] = { 0 };
        int expr_count = 0;
        for (int k = (expr_start_idx == -1 ? 0 : expr_start_idx); k < elem_count; k++) 
        {
            if (strcmp(elements[k], ";") == 0) break;
            strcpy(expr_elements[expr_count++], elements[k]);
        }
        infix_to_postfix(expr_elements, expr_count, postfix, &postfix_len);
        if (postfix_len > 0)
        {
            if (calculate_postfix(postfix, postfix_len, &calc_result) == 0)
            {
                if (expr_start_idx != -1)
                {
                    update_var(var_name, calc_result);
                }
            }
        }
        if (!has_semicolon) 
            printf("%.6f\n", calc_result);
    }
    fclose(commands);
    return 0;
}