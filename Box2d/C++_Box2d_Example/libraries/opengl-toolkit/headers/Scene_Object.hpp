
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

#ifndef OPENGL_TOOLKIT_SCENE_OBJECT_HEADER
#define OPENGL_TOOLKIT_SCENE_OBJECT_HEADER

    #include <cassert>
    #include <Math.hpp>
    #include <Material.hpp>

    namespace toolkit
    {

        class Scene;

        class Scene_Object
        {
        private:

            typedef Matrix44 Transformation;

        protected:

            Scene        * scene;

            Transformation local_scale;
            Transformation local_anchor;
            Transformation transformation;

            bool           visible;

        protected:

            Scene_Object()
            {
                scene   = nullptr;
                visible = true;
            }

            virtual ~Scene_Object()
            {
            }

        public:

            void set_parent_scene (Scene * parent_scene)
            {
                assert(scene == nullptr);                   // Sólo puede tener un parent...

                scene = parent_scene;
            }

            Scene * get_scene ()
            {
                return scene;
            }

            void set_visible (bool state)
            {
                visible = state;
            }

            bool is_visible () const
            {
                return visible;
            }

            bool is_not_visible () const
            {
                return visible == false;
            }

        public:

            const Transformation & get_transformation () const
            {
                return transformation;
            }

            Transformation get_inverse_transformation () const
            {
                return toolkit::inverse (transformation);
            }

            void reset_transformation ()
            {
                transformation = local_scale * local_anchor;
            }

            void reset_transformation (float new_scale)
            {
                local_scale    = toolkit::scale (Matrix44(), new_scale);
                transformation = local_scale * local_anchor;
            }

            void reset_transformation (float new_scale, const Vector3 & new_anchor)
            {
                local_scale    = toolkit::scale     (Matrix44(), new_scale );
                local_anchor   = toolkit::translate (Matrix44(), new_anchor);
                transformation = local_scale * local_anchor;
            }

            void translate (const Vector3 & displacement)
            {
                transformation = toolkit::translate (transformation, displacement);
            }

            void scale (float scale)
            {
                transformation = toolkit::scale (transformation, scale);
            }

            void scale (float scale_x, float scale_y, float scale_z)
            {
                transformation = toolkit::scale (transformation, scale_x, scale_y, scale_z);
            }

            void rotate_around_x (float angle)
            {
                transformation = toolkit::rotate_around_x (transformation, angle);
            }

            void rotate_around_y (float angle)
            {
                transformation = toolkit::rotate_around_y (transformation, angle);
            }

            void rotate_around_z (float angle)
            {
                transformation = toolkit::rotate_around_z (transformation, angle);
            }

        public:

            virtual bool changes_shaders () const
            {
                return false;
            }

            virtual void shader_changed (const Shader_Program & )
            {
            }

        };

    }

#endif
