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
            void circle(float cx, float cy, float r, int num_segments, const Color color);
            
            public:

            void Setup(void) override;
            void Update(void) override;

            void ChangeColor(const Color _color);

            Color GetColor(void) const;

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

            };
            class ForceLines: public Drawable {
                public:
                
                void Setup(void) override;
                void Draw(void) override;

            };
        }

        class Collidable: public Component {
            public:
            void Setup(void) override;
            void Update(void) override;
        };

        namespace collidables {
            class SegmentCollider: public Collidable {
                public:

                Vector2D start;
                Vector2D end;

                void Setup(void) override;
                void Update(void) override;

                bool DoesIntersect(SegmentCollider* possibleIntersectingSegment);

            };
        }
    }
}