
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

#ifndef OPENGL_TOOLKIT_SHAPE_SET_HEADER
#define OPENGL_TOOLKIT_SHAPE_SET_HEADER

    #include <list>
    #include <memory>
    #include <Shape.hpp>

    namespace toolkit
    {

        class Shape_Set : public Drawable
        {
        private:

            typedef std::list< std::shared_ptr< Shape > > Shape_List;

        private:

            Shape_List shape_list;

        public:

            void add_shape (const std::shared_ptr< Shape > & shape)
            {
                shape_list.push_back (shape);
            }

        public:

            virtual void draw ()
            {
                for (auto & shape : shape_list)
                {
                    shape->draw ();
                }
            }

        };

    }

#endif
