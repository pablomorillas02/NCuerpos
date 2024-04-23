//  Created by Antonio J. Rueda on 21/3/2024.
//  Copyright © 2024 Antonio J. Rueda.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef glfwwindow_h
#define glfwwindow_h

#include <iostream>

#include <GLFW/glfw3.h>

/** Tipos de eventos */
enum GLFWEvent {
    KEYEVENT = 0x1,
    CHAREVENT = 0x2,
    SIZEEVENT = 0x4,
    MOUSEBUTTONEVENT = 0x8,
    CURSORPOSEVENT = 0x10,
    SCROLLEVENT = 0x20,
    CLOSEEVENT = 0x40,
    REFRESHEVENT = 0x80,
    FOCUSEVENT = 0x100
};

/** Encapsulación de ventanas de GLFW
 Contiene las funciones principales y la gestión de eventos evitando
 el uso directo de callbacks */
class GLFWWindow {
    GLFWwindow *window;
    
    int capturedEvents;
    
    static void sizeCallback(GLFWwindow *window, int width, int height) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->sizeEvent(width, height);
    }
    static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->mouseButtonEvent(button, action, mods);
    }
    static void cursorPosCallback(GLFWwindow *window, double x, double y) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->cursorPosEvent(x, y);
    }
    static void scrollCallback(GLFWwindow *window, double xoffset, double yoffset) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->scrollEvent(xoffset, yoffset);
    }
    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->keyEvent(key, scancode, action, mods);
    }
    static void charCallback(GLFWwindow *window, unsigned int codepoint) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->charEvent(codepoint);
    }
    static void closeCallback(GLFWwindow *window) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->closeEvent();
    }
    static void refreshCallback(GLFWwindow *window) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->refreshEvent();
    }
    static void focusCallback(GLFWwindow *window, int focused) {
        ((GLFWWindow *)glfwGetWindowUserPointer(window))->focusEvent(focused);
    }
    
public:
    GLFWWindow(int width, int height, const char *title, GLFWmonitor *monitor = 0, GLFWwindow *share = 0);
    void setTitle(const char *title) { glfwSetWindowTitle(window, title); }
    void show() { glfwShowWindow(window); }
    void hide() { glfwHideWindow(window); }
    
    void makeContextCurrent() {
        glfwMakeContextCurrent(window);
        glfwSwapInterval(0);
    }
    
    void swapBuffers() { glfwSwapBuffers(window); }
    void getFramebufferSize(int &width, int &height) {
        glfwGetFramebufferSize(window, &width, &height);
    }
    
    int getCapturedEvents() { return capturedEvents; }
    void setCapturedEvents(int events);
    
    void getCursorPos(double &xpos, double &ypos) { return glfwGetCursorPos(window, &xpos, &ypos); }
    
    bool shouldClose() { return glfwWindowShouldClose(window); }
    
    virtual void keyEvent(int key, int scancode, int action, int mods) {};
    virtual void charEvent(unsigned int codepoint) {};
    
    virtual void sizeEvent(int width, int height) {};
    virtual void mouseButtonEvent(int button, int action, int mods) {};
    virtual void cursorPosEvent(double x, double y) {};
    virtual void scrollEvent(double xoffset, double yoffset) {};

    virtual void refreshEvent() {};
    virtual void closeEvent() {};
    virtual void focusEvent(bool focused) {};
    
    static void hint(int target, int hint) { glfwWindowHint(target, hint); }
    
    ~GLFWWindow() {
        glfwDestroyWindow(window);
    }
};

#endif
