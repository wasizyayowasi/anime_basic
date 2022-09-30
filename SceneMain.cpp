#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace {

	//�O���t�B�b�N�t�@�C����
	const char* const kPlayerGraphicFilename = "data/char.png";

	//�v���C���[�O���t�B�b�N������
	constexpr int kPlayerGraphicDivX = 3;
	constexpr int kPlayerGraphicDivY = 4;
	constexpr int kPlayerGraphicDivNum = kPlayerGraphicDivX * kPlayerGraphicDivY;

	//�v���C���[�O���t�B�b�N�T�C�Y
	constexpr int kPlayerGraphicSizeX = 32;
	constexpr int kPlayerGraphicSizeY = 32;
}


SceneMain::SceneMain()
{
	
	for (auto& handle:m_hPlayerGraphic) {
		handle = -1;
	}
}

SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	LoadDivGraph(kPlayerGraphicFilename, kPlayerGraphicDivNum, kPlayerGraphicDivX, kPlayerGraphicDivY, kPlayerGraphicSizeX, kPlayerGraphicSizeY, m_hPlayerGraphic);
	
	for (int i = 0; i < kPlayerGraphicDivNum; i++) {
		m_player.setHandle(i,m_hPlayerGraphic[i]);
	}
	
	m_player.init();
}

// �I������
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic) {
		DeleteGraph(handle);
	}
	
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
}