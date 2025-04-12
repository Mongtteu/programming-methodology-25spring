#include <gtest/gtest.h>
#include "todo.h"
#include <stdexcept>

TEST(TodoListTest, AddSingleTask) {
    TodoList todo;
    todo.init();
    todo.add_task("Write code");

    int count;
    const char** tasks = todo.get_pending_tasks(count);

    ASSERT_EQ(count, 1);
    EXPECT_STREQ(tasks[0], "Write code");

    todo.destroy();
}

TEST(TodoListTest, AddMultipleTasks) {
    TodoList todo;
    todo.init();
    todo.add_task("A");
    todo.add_task("B");
    todo.add_task("C");

    int count;
    const char** tasks = todo.get_pending_tasks(count);
    ASSERT_EQ(count, 3);
    EXPECT_STREQ(tasks[0], "A");
    EXPECT_STREQ(tasks[1], "B");
    EXPECT_STREQ(tasks[2], "C");

    todo.destroy();
}

TEST(TodoListTest, RemoveTask) {
    TodoList todo;
    todo.init();
    todo.add_task("A");
    todo.add_task("B");
    todo.add_task("C");

    todo.remove_task(1);  // Remove "B"

    int count;
    const char** tasks = todo.get_pending_tasks(count);
    ASSERT_EQ(count, 2);
    EXPECT_STREQ(tasks[0], "A");
    EXPECT_STREQ(tasks[1], "C");

    todo.destroy();
}

TEST(TodoListTest, RemoveInvalidIndexThrows) {
    TodoList todo;
    todo.init();
    todo.add_task("Sample Task");

    EXPECT_THROW(todo.remove_task(-1), std::invalid_argument); // 음수 인덱스
    EXPECT_THROW(todo.remove_task(1), std::invalid_argument);  // 범위 초과 인덱스

    todo.destroy();
}

TEST(TodoListTest, AddTooManyTasksThrows) {
    TodoList todo;
    todo.init();

    for (int i = 0; i < 32; ++i) {
        todo.add_task("overflow test");
    }
    EXPECT_THROW(todo.add_task("33rd"), std::overflow_error);  // 초과 시도

    todo.destroy();
}
