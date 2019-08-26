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

            void line(const float x1, const float y1, const float x2, const float y2, const Color color);

            //void arrow(const float x1, const float y1, const float x2, const float y2, const Color color);

            void fcircle(float x, float y, float radius, const Color color, const int triangles);
            void circle(float cx, float cy, float r, const Color color, int num_segments);
            
            public:

            void Setup(void) override;
            void Update(void) override;

            Color color = Color::Blue;

            void ChangeColor(const Color _color);
            Color GetColor(void) const;

            static Vector2D getScreenSize();

        };

        namespace drawables {
            class Circle: public Drawable {
                protected:
                
                void Setup(void) override;
                void Draw(void) override;

                public:
                int raidius;
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
            class Line: public Drawable {
                protected:

                Color color;
                
                void Setup(void) override;
                void Draw(void) override;

                public:
                
                Vector2D startingOffset;
                Vector2D endingOffset;

                void SetStartingOffset(const Vector2D &_startingOffset);
                void SetEndingOffset(const Vector2D &_endingOffset);
                void SetStartingAndEndingOffset(const Vector2D &_startingOffset, const Vector2D &_endingOffset);

                static void DrawLine(const float x1, const float y1, const float x2, const float y2, const Color color);

            };
            class ForceLines: public Drawable {
                public:
                
                void Setup(void) override;
                void Draw(void) override;

            };
        }

        class Collidable: public Component {
            public:

            static vector<Collidable*> collidables;

            void Setup(void) override;
            void Update(void) override;
        };

        namespace collidables {

            class SegmentCollider: public Collidable {
                public:

                physics::Point start;
                physics::Point end;

                void Setup(void) override;
                void Update(void) override;

                bool DoesIntersect(SegmentCollider* possibleIntersectingSegment);

            };
        }
    }
}