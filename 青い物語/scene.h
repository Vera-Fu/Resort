#ifndef SCENE_H_
#define SCENE_H_

int GetScene(void);
void SetScene(int scene);

enum SCENE
{
	TITLESCENE,
	LEVELCHANGESCENE,
	GAMESCENE,
	ENDSCENE
};

#endif // !SCENE_H_

