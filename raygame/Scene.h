#pragma once
#include "Actor.h"
#include "Wall.h"

class Scene
{
public:
    Scene();

    /// <returns>If this scene is the current active scene in the game.</returns>
    bool getStarted() { return m_started; }

    /// <returns>The scenes matrix that represents the world transform.</returns>
    MathLibrary::Matrix3* getWorld();

    /// <summary>
    /// Adds the given actor to the array of actors so that the scene may call its update and draw functions.
    /// </summary>
    /// <param name="actor">The actor to add to the scene.</param>
    void addActor(Actor* actor);

    /// <summary>
    /// Removes the actor at the given index. DOES NOT DELETE THE ACTOR!!!
    /// </summary>
    /// <param name="index">The index the actor is in the scene's array.</param>
    /// <returns>False if the index given is out of bounds.</returns>
    bool removeActor(int index);

    /// <summary>
    /// Removes the actor given if it's in the array. DOES NOT DELETE THE ACTOR!!!
    /// </summary>
    /// <param name="actor">The actor to look for in the scene's array.</param>
    /// <returns>False if the actor is a nullptr or isn't in the array.</returns>
    bool removeActor(Actor* actor);

    //Same as addActor function with the parameter changed to take in a wall instead
    void addWall(Wall* wall);

    //Same as removeActor but used to remove walls from the scene
    bool removeWall(int index);

    bool removeWall(Wall* wall);

    virtual void start();

    /// <summary>
    /// Checks if any actor has collided in scene. Calls the actors onCollision function if so.
    /// </summary>
    virtual void checkCollision();

    virtual void update(float deltaTime);

    virtual void draw();

    virtual void debug();

    virtual void end();

private:
    Actor** m_actors;
    MathLibrary::Matrix3* m_world;
    bool m_started;
    int m_actorCount;

    Wall** m_walls;
    int m_wallsCount;

};

