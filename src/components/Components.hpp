#pragma once

#include <iostream>
#include <string>
#include "../Component.hpp"
#include "../Physics.hpp"

namespace obiectum {

    namespace components {

        using namespace std;
        using namespace physics;

        class Transform: public Component {
            public:

            Vector2D position;
            Vector2D velocity;

            void Setup(void) override;
            void Update(void) override;
        };

        class RigidBody: public Component {

            // Pointer to the Transform Component
            Transform* transform;

            public:

            float mass;
            float drag;

            void Setup(void) override;
            void Update(void) override;

        };

        class Drawable: public Component {
            protected:
            Transform* transform;

            virtual void Draw(void) = 0;

            static bool isSetup;

            // Drop gl implementations here

            void hrect(const float x1, const float y1, const float x2, const float y2, const Color color);
            void rect(const float x1, const float y1, const float x2, const float y2, const Color color);

            void fcircle(float x, float y, float radius, const Color color, const int triangles);
            void circle(float cx, float cy, float r, int num_segments, const Color color);
            
            public:

            void Setup(void) override;
            void Update(void) override;


            static Vector2D getScreenSize();

        };

        namespace drawables {
            class Circle: public Drawable {
                protected:

                Color color;

                int raidius;
                
                void Setup(void) override;
                void Draw(void) override;

                public:
                int detail;

            };
            class Square: public Drawable {
                protected:

                Color color;
                
                void Setup(void) override;
                void Draw(void) override;

                public:
                float diameter;
                Vector2D offset;
                void Center(const Vector2D _offset);

            };
        }
    }
}