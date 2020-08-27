#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Glew must be initialized after OpenGL context be created
    if (glewInit() != GLEW_OK)
        std::cout << "GlEW ERROR" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    // Best OpenGL documentation: http://docs.gl/

    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    // Modern OpenGL works like a state machine

    // State: Generate Buffer
    unsigned int buffer; // Id for the generated buffer
    glGenBuffers(1, &buffer);

    // State: Select buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    // State: Populate buffer data
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        // State: Draw
        // (MODE, start_vertex, vertex_count)
        // This will draw the glBindBuffer 
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}