#include <GLFW/glfw3.h>
#include <string>

// Base class for my monstrosity that I created
class OpenglThing {
    // Pointer to a boolean in the main file that is used to determine whether the program's loop
    // should keep iterating
    // 
    // true or 1: the program will keep running
    // false or 0: the program stops
    bool *is_running;
    // The program's window
    GLFWwindow *window;
    public:
    OpenglThing(bool *running, char *name, int width, int height);
    ~OpenglThing();
    void stop_program();
    GLFWwindow *get_window();
};
