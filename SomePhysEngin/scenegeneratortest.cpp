/*
 * This is created by LM
 * for testing scene generator
 * 2015/12
 */
#include "scenegeneratortest.h"
#include <QString>

SceneGeneratorTest::SceneGeneratorTest(QWidget *parent):QPlainTextEdit(parent)
{
    setPlaceholderText("Scene showed here");
}

void SceneGeneratorTest::reset_scene(const QString& scene_content)
{
    setPlaceholderText(scene_content);
}


void SceneGeneratorTest::update()
{

}
