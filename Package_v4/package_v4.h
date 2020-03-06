#ifndef PACKAGE_V4_H
#define PACKAGE_V4_H

#include <QtWidgets/QWidget>
#include "ui_package_v4.h"

class Package_v4 : public QWidget
{
	Q_OBJECT

public:
	Package_v4(QWidget *parent = 0);
	~Package_v4();

	///��ʼ��
	void Init();

	///·����ʼ��
	void Init_DirPath();

	///�����ļ���
	bool Create_Dir(const QString &path);

	///�����ļ���
	bool Copy_Dir(const QString &fromDir, const QString &toDir, bool coverFileIfExist);

	///�����ļ�
	bool Copy_File(QString sourceDir, QString toDir, bool coverFileIfExist);

	///�滻��Ҫ�޸ĵ��ļ�
	bool Replace_File(const QString &frompath, const QString & topath);

	///7za����
	bool Fun_Do7za(const QString& str7za);

	///ɾ���ļ��л��ļ�
	bool DeleteFileOrDir(const QString &Path);

	///��������
	bool Fun_isRequired();

	///ִ�д��
	bool Fun_StartPackage();

	///����ɹ���ʾ
	void Fun_PackCompleteTip();

private:
	Ui::Package_v4Class ui;

	QString m_qsCurrentPath;
	QString m_qsParentPath;
	QString m_qsResourcePath;

	QString m_qValue_1;
	QString m_qValue_2;
	QString m_qValue_3;
	QString m_qValue_4;
	QString m_qValue_5;
	QString m_qValue_6;
	QString m_qValue_7;
	QString m_qValue_8;
	QString m_qValue_9;
	QString m_qValue_10;
	QString m_qValue_11;
	QString m_qValue_12;
	QString m_qValue_13;
	QString m_qValue_14;
	QString m_qValue_15;

	QString m_qDirPath2;
	QString m_qDirPath3;
	QString m_qDirPath4;
	QString m_qDirPath5;
	QString m_qDirPath6;
	QString m_qDirPath7_From;
	QString m_qDirPath7_To;
	QString m_qDirPath8_From;
	QString m_qDirPath8_To;
	QString m_qDirPath9_From;
	QString m_qDirPath9_To;
	QString m_qDirPath10_From;
	QString m_qDirPath10_To;
	QString m_qDirPath11_From;
	QString m_qDirPath11_To;
	QString m_qDirPath12_From;
	QString m_qDirPath12_To;
	QString m_qDirPath13_From;
	QString m_qDirPath13_To;
	QString m_qDirPath14;
	QString m_qDirPath15;
	QString m_qDirPath16;
	QString m_qDirPath17_From;
	QString m_qDirPath17_To;
	QString m_qDirPath18_From;
	QString m_qDirPath18_To;
	QString m_qDirPath19_From;
	QString m_qDirPath19_To;
	QString m_qDirPath20_From;
	QString m_qDirPath20_To;
	QString m_qDirPath21;
	QString m_qDirPath22;
	QString m_qDirPath23;
	QString m_qDirPath24;
	QString m_qDirPath25_From;
	QString m_qDirPath25_To;
	QString m_str7zaPath;
	QString m_strSourceJarPath;
	QString m_str7za_e;
	QString m_str7za_a;
	QString m_qDirPath26;
	QString m_qDirPath27_From;
	QString m_qDirPath27_To;
	QString m_str7za_aall;
	QString m_qDirPath28_From;
	QString m_qDirPath28_To;
	QString m_qDirPath29;

	const char* c_strTrue = "��";
	const char* c_strFalse = "��";
	QString m_qsTrue = QString::fromLocal8Bit(c_strTrue);
	QString m_qsFalse = QString::fromLocal8Bit(c_strFalse);
	QString m_qIsUniversal;
	QString m_qsSelectFileName;
	QString m_qsSelectFilepath;
};

#endif // PACKAGE_V4_H
