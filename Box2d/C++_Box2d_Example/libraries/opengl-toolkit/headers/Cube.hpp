
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                             *
 *  Copyright © 2016+ Ángel Rodríguez Ballesteros                              *
 *                                                                             *
 *  Distributed under the Boost Software License, version  1.0                 *
 *  See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt                 *
 *                                                                             *
 *  Started by Ángel on april of 2016                                          *
 *                                                                             *
 *  angel.rodriguez@esne.edu                                                   *
 *                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef OPENGL_TOOLKIT_CUBE_HEADER
#define OPENGL_TOOLKIT_CUBE_HEADER

    #include <Shape.hpp>

    namespace toolkit
    {

        class Cube : public Shape
        {
        private:

            // Arrays de datos del cubo base:

            static const GLfloat coordinates[];
            static const GLfloat normals    [];
            static const GLfloat texture_uvs[];
            static const GLubyte indices    [];

        public:

            Cube();

        };

    }

#endif
