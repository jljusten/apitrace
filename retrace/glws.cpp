/**************************************************************************
 *
 * Copyright 2011 Jose Fonseca
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 **************************************************************************/


#include <assert.h>

#include <iostream>

#include "glproc.hpp"
#include "glws.hpp"


namespace glws {


bool
checkExtension(const char *extName, const char *extString)
{
    assert(extName);

    if (!extString) {
        return false;
    }

    const char *p = extString;
    const char *q = extName;
    char c;
    do {
        c = *p++;
        if (c == '\0' || c == ' ') {
            if (q && *q == '\0') {
                return true;
            } else {
                q = extName;
            }
        } else {
            if (q && *q == c) {
                ++q;
            } else {
                q = 0;
            }
        }
    } while (c);
    return false;
}


void
Drawable::copySubBuffer(int x, int y, int width, int height) {
    std::cerr << "warning: copySubBuffer not yet implemented\n";
}


bool
Context::hasExtension(const char *string) {
    if (extensions.strings.empty()) {
        extensions.getCurrentContextExtensions(profile);
    }

    return extensions.has(string);
}


} /* namespace glws */
