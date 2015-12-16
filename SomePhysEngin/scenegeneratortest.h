/*
 * This is created by LM
 * for testing scene generator
 * 2015/12
 */
#ifndef SCENEGENERATORTEST_H
#define SCENEGENERATORTEST_H
#include <QPlainTextEdit>

class SceneGeneratorTest: public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit SceneGeneratorTest(QWidget *parent = 0);
    void reset_scene(const QString& scene_content);
    void update();
};

#endif // SCENEGENERATORTEST_H
