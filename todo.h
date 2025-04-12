#ifndef TODO_H
#define TODO_H

class TodoList {
public:
    void init();     
    void destroy();  

    void add_task(const char* task);
    void remove_task(int index);
    const char** get_pending_tasks(int& count) const;

private:
    static const int MAX_TASKS = 32;
    char* tasks[MAX_TASKS];
    int size;

    int string_length(const char* str) const;
    void string_copy(char* dest, const char* src) const;
};

#endif 
