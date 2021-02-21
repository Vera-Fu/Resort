#ifndef SCENE_H_
#define SCENE_H_

int GetScene(void);
void SetScene(int scene);
void ClearScene(void);

enum SCENE
{
	TITLESCENE,
	LEVELCHOOSESCENE,
	GAMESCENE,
	ENDSCENE
};

#endif // !SCENE_H_

