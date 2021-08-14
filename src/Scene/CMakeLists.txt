target_sources(executable PUBLIC
    Scene.h
    Scene.cpp
    Entity.h
    Entity.cpp
    ISystem.h
	SceneManager.cpp
	SceneManager.h
)

add_subdirectory(SceneFactories)