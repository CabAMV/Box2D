
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

#ifndef OPENGL_TOOLKIT_SHAPE_HEADER
#define OPENGL_TOOLKIT_SHAPE_HEADER

    #include <memory>
    #include <cassert>
    #include <OpenGL.hpp>
    #include <Drawable.hpp>
    #include <Vertex_Array_Object.hpp>

    namespace toolkit
    {

        class Shape : public Drawable
        {
        public:

            enum Vertex_Attribute
            {
                COORDINATES,
                NORMALS
            };

        protected:

            GLenum  primitive_type;
            GLenum  indices_type;
            GLsizei vertices_count;

            std::shared_ptr< Vertex_Array_Object > vao;

        protected:

            Shape()
            :
                primitive_type(GL_NONE),
                indices_type  (GL_NONE),
                vertices_count(0      )
            {
            }

            Shape(GLenum primitive_type)
            :
                primitive_type(primitive_type),
                indices_type  (GL_NONE       ),
                vertices_count(0             )
            {
            }

            Shape(GLenum primitive_type, GLsizei vertices_count, GLenum indices_type = GL_NONE)
            :
                primitive_type(primitive_type),
                indices_type  (indices_type  ),
                vertices_count(vertices_count)
            {
                assert(vertices_count > 0);
            }

            virtual ~Shape()
            {
            }

        public:

            void set_primitive_type (GLenum new_primitive_type)
            {
                primitive_type = new_primitive_type;
            }

            void set_indices_type (GLenum new_indices_type)
            {
                indices_type = new_indices_type;
            }

            void set_vertices_count (GLsizei new_vertices_count)
            {
                vertices_count = new_vertices_count;
            }

        public:

            virtual void draw ()
            {
                if (vao.get ())
                {
                    assert(primitive_type != GL_NONE);
                    assert(vertices_count >  0);

                    vao->bind ();

                    if (indices_type == GL_NONE)
                    {
                        glDrawArrays (primitive_type, 0, vertices_count);
                    }
                    else
                    {
                        glDrawElements (primitive_type, vertices_count, indices_type, 0);
                    }

                    vao->unbind ();
                }
            }

        };

    }

#endif
