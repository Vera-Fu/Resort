#include "scene.h"

int g_scene = TITLESCENE;

int GetScene(void)
{
	return g_scene;
}

void SetScene(int scene)
{
	g_scene = scene;
}
