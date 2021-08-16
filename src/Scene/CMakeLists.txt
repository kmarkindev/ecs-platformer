target_sources(executable PUBLIC
    Scene.h
    Scene.cpp
    Entity.h
    Entity.cpp
    ISystem.h
	SceneManager.cpp
	SceneManager.h
	EventListener.h
	EventListener.cpp
)

add_subdirectory(SceneFactories)
add_subdirectory(Events)