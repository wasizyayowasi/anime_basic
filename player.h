#pragma once

#include "Vec2.h"

class Player
{
public:
	Player();
	virtual ~Player();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int index,int handle) { m_handle[index] = handle; }

	// �v���C���[�̏�����
	void init();

	// ����
	void update();
	// �`��
	void draw();

private:
	int m_handle[12];

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

	//�L�����N�^�[�̃A�j���[�V����
	int m_animeNo;

};