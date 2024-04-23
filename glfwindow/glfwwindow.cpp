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

#include <cstdlib>
#include "glfwwindow.h"

GLFWWindow::GLFWWindow(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share) {
    window = glfwCreateWindow(width, height, title, monitor, share);
    capturedEvents = 0;
    
    if (window) {
        glfwSetWindowUserPointer(window, this);
    }
    else {
        std::cerr << "Error al crear ventana" << std::endl;
        exit(1);
    }
}

void GLFWWindow::setCapturedEvents(int events) {
    capturedEvents = events;
    
    if (capturedEvents & KEYEVENT) glfwSetKeyCallback(window, keyCallback);
    if (capturedEvents & CHAREVENT) glfwSetCharCallback(window, charCallback);
    if (capturedEvents & SCROLLEVENT) glfwSetScrollCallback(window, scrollCallback);
    if (capturedEvents & MOUSEBUTTONEVENT) glfwSetMouseButtonCallback(window, mouseButtonCallback);
    if (capturedEvents & CURSORPOSEVENT) glfwSetCursorPosCallback(window, cursorPosCallback);
    if (capturedEvents & SIZEEVENT) glfwSetWindowSizeCallback(window, sizeCallback);
    if (capturedEvents & CLOSEEVENT) glfwSetWindowCloseCallback(window, closeCallback);
    if (capturedEvents & REFRESHEVENT) glfwSetWindowRefreshCallback(window, refreshCallback);
    if (capturedEvents & FOCUSEVENT) glfwSetWindowFocusCallback(window, focusCallback);
}


