#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>       // std::cout
#include <thread>         // std::thread

#include <vector>

using namespace std;

void RENDERLOOP() {
	cout << "test";
}

void render();

int main() {
	vector<int> wut;

	std::thread thread1(RENDERLOOP);
	thread1.join();                // pauses until first finishes

	GLFWwindow* w;

	if (!glfwInit())
		return -1;

	w = glfwCreateWindow(640, 480, "Hello WorldTHREDsdfZ", NULL, NULL);
	if (!w) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(w);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		return -1;
	}

	while (!glfwWindowShouldClose(w)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        render();
		glfwSwapBuffers(w);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}




void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
}

