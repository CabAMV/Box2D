
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

#ifndef OPENGL_TOOLKIT_SCENE_HEADER
#define OPENGL_TOOLKIT_SCENE_HEADER

    #pragma warning(disable: 4503)          // Deshabilita un warning que ocurre en la implementación
                                            // de Microsoft de la librería estándar
    #include <map>
    #include <list>
    #include <memory>
    #include <string>
    #include <Camera.hpp>
    #include <Drawable.hpp>
    #include <Material.hpp>
    #include <Scene_Object.hpp>

    namespace toolkit
    {

        class Scene
        {
        private:

            typedef std::list< Drawable *                                         > Drawables;
            typedef std::map < Scene_Object * ,   Drawables                       > Drawables_By_Object;
            typedef std::map < Material * ,       Drawables_By_Object             > Drawables_By_Material;
            typedef std::map < Shader_Program * , Drawables_By_Material           > Drawables_By_Shader;
            typedef std::map < std::string,       std::shared_ptr< Scene_Object > > Scene_Object_Map;
            typedef std::list< Scene_Object *                                     > Scene_Object_List;

        private:

            static const size_t max_number_of_lights = 3;

        private:

            Scene_Object_Map    scene_objects;                      ///< Mapa de todos los objetos de la escena.
            Drawables_By_Shader drawable_list;                      ///< Lista estructurada de drawables que hay que renderizar.
            Scene_Object_List   shader_update_list;                 ///< Lista de scene objects que hay que avisar cuando se cambia de shader.

            Camera            * active_camera;                      ///< Puntero a la cámara activa. Debe haber una para poder hacer un render.
            GLuint              number_of_lights;                   ///< Contador de luces presentes en la escena. Se utiliza para asignar un índice a cada una.

        public:

            Scene()
            {
                active_camera    = nullptr;
                number_of_lights = 0;
            }

        public:

            bool add (const std::string & name, std::shared_ptr< Scene_Object > scene_object);

            Scene_Object * get (const std::string & name);

            bool set_active_camera (const std::string & name);

            Camera * get_active_camera ()
            {
                return active_camera;
            }

        public:

            bool render ();

        public:

            Scene_Object * operator [] (const std::string & name)
            {
                return get (name);
            }

        };

    }

#endif
