#pragma once

#include "player.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
	
private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic[12];
	// �v���C���[
	Player m_player;
};