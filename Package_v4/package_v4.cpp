#include "stdafx.h"
#include "package_v4.h"

Package_v4::Package_v4(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	Init();
	
	connect(ui.str_ComboBox16, &QComboBox::currentTextChanged, this, [=]() 
	{
		QString str_CurrentText = ui.str_ComboBox16->currentText();

		if (m_qsFalse == str_CurrentText)  
		{
			ui.pushButton3_SelectFile->setEnabled(true);
			ui.str_LineEdit16->setEnabled(true);
			m_qIsUniversal = m_qsFalse;
		}
		else if (m_qsTrue == str_CurrentText)
		{
			ui.pushButton3_SelectFile->setEnabled(false);
			ui.str_LineEdit16->setEnabled(false);
			m_qIsUniversal = m_qsTrue;
			ui.str_LineEdit16->setText("");
		}
	});

	connect(ui.pushButton3_SelectFile, &QPushButton::clicked, this, [=]()
	{
		QDir dir;
		QFileInfo fi;
		QString filter;
		filter = "Jar file (*.jar*)";
		QString SelectFile = QFileDialog::getOpenFileName(NULL, QString("Please Select Jar File"), dir.absolutePath(), filter);
		fi = QFileInfo(SelectFile);
		m_qsSelectFileName = fi.fileName();
		m_qsSelectFilepath = fi.absoluteFilePath();
		ui.str_LineEdit16->setText(m_qsSelectFilepath);
	});

	connect(ui.pushButton2_Confrim, &QPushButton::clicked, this, [=]()
	{
		Init_DirPath();

		bool bRet = Fun_isRequired();
		if (true == bRet)
		{
			bool bRet = Fun_StartPackage();
			if (true == bRet)
			{
				Fun_PackCompleteTip();
			}
		}
	});
}
 
Package_v4::~Package_v4()
{

}

///初始化
void Package_v4::Init()
{
	ui.pushButton3_SelectFile->setEnabled(false);
	ui.str_LineEdit16->setEnabled(false);
	m_qIsUniversal = m_qsTrue;
}

///路径初始化
void Package_v4::Init_DirPath()
{
	m_qValue_1 = ui.str_LineEdit1->text();
	m_qValue_2 = ui.str_LineEdit2->text();
	m_qValue_3 = ui.str_LineEdit3->text();
	m_qValue_4 = ui.str_LineEdit4->text();
	m_qValue_5 = ui.str_LineEdit5->text();
	m_qValue_6 = ui.str_LineEdit6->text();
	m_qValue_7 = ui.str_LineEdit7->text();
	m_qValue_8 = ui.str_LineEdit8->text();
	m_qValue_9 = ui.str_LineEdit9->text();
	m_qValue_10 = ui.str_LineEdit10->text();
	m_qValue_11 = ui.str_LineEdit11->text();
	m_qValue_12 = ui.str_LineEdit12->text();
	m_qValue_13 = ui.str_LineEdit13->text();
	m_qValue_14 = ui.str_LineEdit14->text();
	m_qValue_15 = ui.str_ComboBox15->currentText();

	QDir CurrentDir;
	m_qsCurrentPath = QDir::currentPath();
	CurrentDir.setPath(m_qsCurrentPath);
	CurrentDir.cd("xres_resource_{1}_{2}_1.0.0");
	m_qsResourcePath = CurrentDir.path();
	CurrentDir.cd("../../");
	m_qsParentPath = CurrentDir.path();

	

	m_qDirPath2 = m_qsCurrentPath + QString::fromLocal8Bit("/META-INF");
	m_qDirPath3 = m_qsCurrentPath + QString::fromLocal8Bit("/minio_assistant_") + m_qValue_2;
	m_qDirPath4 = m_qsCurrentPath + QString::fromLocal8Bit("/script");
	m_qDirPath5 = m_qsCurrentPath + QString::fromLocal8Bit("/xres-rms");
	m_qDirPath6 = m_qsCurrentPath + QString::fromLocal8Bit("/xres-trigger");
	m_qDirPath7_From = m_qsResourcePath + QString::fromLocal8Bit("/META-INF/packageinfo.xml");
	m_qDirPath7_To = m_qDirPath2 + QString::fromLocal8Bit("/packageinfo.xml");
	m_qDirPath8_From = m_qsResourcePath + QString::fromLocal8Bit("/minio_assistant_{2}/bicIdentify");
	m_qDirPath8_To = m_qDirPath3 + QString::fromLocal8Bit("/bicIdentify");
	m_qDirPath9_From = m_qsResourcePath + QString::fromLocal8Bit("/minio_assistant_{2}/minio_assistant_amd64");
	m_qDirPath9_To = m_qDirPath3 + QString::fromLocal8Bit("/minio_assistant_amd64");
	m_qDirPath10_From = m_qsResourcePath + QString::fromLocal8Bit("/minio_assistant_{2}/minio_assistant_arm8_huawei");
	m_qDirPath10_To = m_qDirPath3 + QString::fromLocal8Bit("/minio_assistant_arm8_huawei");
	m_qDirPath11_From = m_qsResourcePath + QString::fromLocal8Bit("/minio_assistant_{2}/upload_2_minio.sh");
	m_qDirPath11_To = m_qDirPath3 + QString::fromLocal8Bit("/upload_2_minio.sh");
	m_qDirPath12_From = m_qsResourcePath + QString::fromLocal8Bit("/minio_assistant_{2}/minio_upload.xml");
	m_qDirPath12_To = m_qDirPath3 + QString::fromLocal8Bit("/minio_upload.xml");
	m_qDirPath13_From = m_qsResourcePath + QString::fromLocal8Bit("/script/install.sh");
	m_qDirPath13_To = m_qDirPath4 + QString::fromLocal8Bit("/install.sh");
	m_qDirPath14 = m_qDirPath5 + QString::fromLocal8Bit("/config");
	m_qDirPath15 = m_qDirPath5 + QString::fromLocal8Bit("/expand");
	m_qDirPath16 = m_qDirPath14 + QString::fromLocal8Bit("/menumanufacturer");
	m_qDirPath17_From = m_qsResourcePath + QString::fromLocal8Bit("/xres-rms/expand/data_dicts_xres_{2}_en_US.properties");
	m_qDirPath17_To = m_qDirPath15 + QString::fromLocal8Bit("/data_dicts_xres_") + m_qValue_2 + QString::fromLocal8Bit("_en_US.properties");
	m_qDirPath18_From = m_qsResourcePath + QString::fromLocal8Bit("/xres-rms/expand/data_dicts_xres_{2}_zh_CN.properties");
	m_qDirPath18_To = m_qDirPath15 + QString::fromLocal8Bit("/data_dicts_xres_") + m_qValue_2 + QString::fromLocal8Bit("_zh_CN.properties");
	m_qDirPath19_From = m_qsResourcePath + QString::fromLocal8Bit("/xres-rms/config/menumanufacturer/menu_manufacturer_{2}.xml");
	m_qDirPath19_To = m_qDirPath16 + QString::fromLocal8Bit("/menu_manufacturer_") + m_qValue_2 + QString::fromLocal8Bit(".xml");
	m_qDirPath20_From = m_qsResourcePath + QString::fromLocal8Bit("/xres-rms/expand/data_dicts_xres_{2}.xml");
	m_qDirPath20_To = m_qDirPath15 + QString::fromLocal8Bit("/data_dicts_xres_") + m_qValue_2 + QString::fromLocal8Bit(".xml");
	m_qDirPath21 = m_qDirPath6 + QString::fromLocal8Bit("/config");
	m_qDirPath22 = m_qDirPath6 + QString::fromLocal8Bit("/lib");
	m_qDirPath23 = m_qDirPath21 + QString::fromLocal8Bit("/iconfig");
	m_qDirPath24 = m_qDirPath23 + QString::fromLocal8Bit("/protocol");
	m_qDirPath25_From = m_qsResourcePath + QString::fromLocal8Bit("/xres-trigger/config/iconfig/protocol/manufacturer_protocol_{2}.xml");
	m_qDirPath25_To = m_qDirPath24 + QString::fromLocal8Bit("/manufacturer_protocol_") + m_qValue_2 + QString::fromLocal8Bit(".xml");
	m_str7zaPath = m_qsCurrentPath + QString::fromLocal8Bit("/7za.exe");
	m_strSourceJarPath = m_qsResourcePath + QString::fromLocal8Bit("/xres-trigger/lib/xres-resource-acess-{2}-1.0-SNAPSHOT.jar");
	m_str7zaPath.replace(" ", "\" \"");
	m_strSourceJarPath.replace(" ", "\" \"");
	m_str7za_e = m_str7zaPath + QString::fromLocal8Bit(" e ") + m_strSourceJarPath;//解压
	m_str7za_a = m_str7zaPath + QString::fromLocal8Bit(" a xres-resource-acess-") + m_qValue_2 + QString::fromLocal8Bit("-1.0-SNAPSHOT.jar treate-type-common.properties");
	m_qDirPath26 = m_qsCurrentPath + QString::fromLocal8Bit("/treate-type-common.properties");
	m_qDirPath27_From = m_qsCurrentPath + QString::fromLocal8Bit("/xres-resource-acess-") + m_qValue_2 + QString::fromLocal8Bit("-1.0-SNAPSHOT.jar");
	m_qDirPath27_To = m_qDirPath22 + QString::fromLocal8Bit("/xres-resource-acess-") + m_qValue_2 + QString::fromLocal8Bit("-1.0-SNAPSHOT.jar");
	m_str7za_aall = m_str7zaPath + QString::fromLocal8Bit(" a xres_resource_") + m_qValue_1 + QString::fromLocal8Bit("_") + m_qValue_2 + QString::fromLocal8Bit("_1.0.0.zip META-INF minio_assistant_") + m_qValue_2 + QString::fromLocal8Bit(" script xres-rms xres-trigger");
	m_qDirPath28_From = m_qsCurrentPath + QString::fromLocal8Bit("/xres_resource_") + m_qValue_1 + QString::fromLocal8Bit("_") + m_qValue_2 + QString::fromLocal8Bit("_1.0.0.zip");
	m_qDirPath28_To = m_qsParentPath + QString::fromLocal8Bit("/xres_resource_") + m_qValue_1 + QString::fromLocal8Bit("_") + m_qValue_2 + QString::fromLocal8Bit("_1.0.0.zip");
	m_qDirPath29 = m_qDirPath22 + QString::fromLocal8Bit("/") + m_qsSelectFileName;
}

///创建文件夹
bool Package_v4::Create_Dir(const QString &path)
{
	QDir dir(path);
	if (!dir.exists())
	{
		if (!dir.mkpath(path))
		{
			qDebug() << "Create path fail" << endl;
			return false;
		}
		else
		{
			qDebug() << "Create path success" << endl;
			return true;
		}
	}
	else
	{
		qDebug() << "path exist" << endl;
		return false;
	}
}

///拷贝或重命名文件文件夹
bool Package_v4::Copy_Dir(const QString & fromDir, const QString & toDir, bool coverFileIfExist)
{
	QDir sourceDir(fromDir);
	QDir targetDir(toDir);
	if (!targetDir.exists())
	{
		/* 如果目标目录不存在，则进行创建 */
		if (!targetDir.mkdir(targetDir.absolutePath()))
		{
			return false;
		}
	}

	QFileInfoList fileInfoList = sourceDir.entryInfoList();
	foreach(QFileInfo fileInfo, fileInfoList)
	{
		if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")
		{
			continue;

		}
		if (fileInfo.isDir())
		{    /* 当为目录时，递归的进行copy */
			if (!Copy_Dir(fileInfo.filePath(), targetDir.filePath(fileInfo.fileName()), coverFileIfExist))
			{
				return false;
			}
		}
		else
		{
			/* 当允许覆盖操作时，将旧文件进行删除操作 */
			if (coverFileIfExist && targetDir.exists(fileInfo.fileName()))
			{
				targetDir.remove(fileInfo.fileName());
			}
			/* 进行文件copy */
			if (!QFile::copy(fileInfo.filePath(), targetDir.filePath(fileInfo.fileName())))
			{
				return false;
			}
		}
	}
	return true;
}

///拷贝文件
bool Package_v4::Copy_File(QString sourceDir, QString toDir, bool coverFileIfExist)
{
	toDir.replace("\\", "/");
	if (sourceDir == toDir)
	{
		return true;
	}
	if (!QFile::exists(sourceDir))
	{
		return false;
	}
	QDir *createfile = new QDir;
	bool exist = createfile->exists(toDir);
	if (exist)
	{
		if (coverFileIfExist)
		{
			createfile->remove(toDir);
		}
	}//end if

	if (!QFile::copy(sourceDir, toDir))
	{
		return false;
	}
	return true;
}

///替换需要修改的文件
bool Package_v4::Replace_File(const QString & frompath, const QString & topath)
{
	QString srcData;
	QFile fromfile(frompath);
	if (!fromfile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}
	QByteArray text = fromfile.readAll();
	srcData.prepend(text);
	if (srcData.contains("{1}"))
	{
		srcData.replace("{1}", m_qValue_1);
	}
	if (srcData.contains("{2}"))
	{
		srcData.replace("{2}", m_qValue_2);
	}
	if (srcData.contains("{3}"))
	{
		srcData.replace("{3}", m_qValue_3);
	}
	if (srcData.contains("{4}"))
	{
		srcData.replace("{4}", m_qValue_4);
	}
	if (srcData.contains("{5}"))
	{
		if (m_qValue_5.isEmpty())
		{
			QString qs_TempValue = QString::fromLocal8Bit("<menuManufacturer  dataKey='vss@") + m_qValue_4 + QString::fromLocal8Bit("' 		    dataValue='vss'       sort='2'   treatyType='[{5}]' />");
			srcData.replace(qs_TempValue, "");
		}
		else
		{
			srcData.replace("{5}", m_qValue_5);
		}
	}
	if (srcData.contains("{6}"))
	{
		if (m_qValue_6.isEmpty())
		{
			QString qs_TempValue = QString::fromLocal8Bit("<menuManufacturer  dataKey='ias@") + m_qValue_4 + QString::fromLocal8Bit("' 		    dataValue='ias'       sort='5'   treatyType='[{6}]' />");
			srcData.replace(qs_TempValue, "");
		}
		else
		{
			srcData.replace("{6}", m_qValue_6);
		}
	}
	if (srcData.contains("{7}"))
	{
		if (m_qValue_7.isEmpty())
		{
			QString qs_TempValue = QString::fromLocal8Bit("<menuManufacturer  dataKey='acs@") + m_qValue_4 + QString::fromLocal8Bit("' 		    dataValue='acs'       sort='8'   treatyType='[{7}]'/>");
			srcData.replace(qs_TempValue, "");
		}
		else
		{
			srcData.replace("{7}", m_qValue_7);
		}
	}
	if (srcData.contains("{8}"))
	{
		srcData.replace("{8}", m_qValue_8);
	}
	if (srcData.contains("{9}"))
	{
		srcData.replace("{9}", m_qValue_9);
	}
	if (srcData.contains("{10}"))
	{
		srcData.replace("{10}", m_qValue_10);
	}
	if (srcData.contains("{11}"))
	{
		srcData.replace("{11}", m_qValue_11);
	}
	if (srcData.contains("{12}"))
	{
		srcData.replace("{12}", m_qValue_12);
	}
	if (srcData.contains("{13}"))
	{
		srcData.replace("{13}", m_qValue_13);
	}
	if (srcData.contains("{14}"))
	{
		srcData.replace("{14}", m_qValue_14);
	}
	if (srcData.contains("{15}"))
	{
		if (m_qsTrue == m_qValue_15)
		{
			srcData.replace("{15}", "true");
		}
		else
		{
			srcData.replace("{15}", "false");

		}
	}
	fromfile.close();

	QFile tofile(topath);
	if (tofile.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		tofile.write(srcData.toStdString().data());
		tofile.close();
		return true;
	}
	return false;
}

///7za命令
bool Package_v4::Fun_Do7za(const QString& str7za)
{
	QProcess pZip(0);
	pZip.start(str7za);
	pZip.waitForStarted();
	pZip.waitForFinished();
	return true;
}

///删除文件夹或文件
bool Package_v4::DeleteFileOrDir(const QString & Path)
{
	if (Path.isEmpty() || !QDir().exists(Path))//是否传入了空的路径||路径是否存在
		return false;
	QFileInfo FileInfo(Path);
	if (FileInfo.isFile())//如果是文件
		QFile::remove(Path);
	else if (FileInfo.isDir())//如果是文件夹
	{
		QDir qDir(Path);
		qDir.removeRecursively();
	}
	return true;
}

///必填项检测
bool Package_v4::Fun_isRequired()
{
	if (0 == m_qValue_1 || 0 == m_qValue_2 || 0 == m_qValue_3 || 0 == m_qValue_4 || 0 == m_qValue_8 || 0 == m_qValue_9 || 0 == m_qValue_10 || 0 == m_qValue_11 || 0 == m_qValue_12 || 0 == m_qValue_13 || 0 == m_qValue_14)
	{
		const char* c_dlgTitle = "警告";
		QString dlgTitle = QString::fromLocal8Bit(c_dlgTitle);
		const char* c_strInfo = "必填项未填写完成";
		QString strInfo = QString::fromLocal8Bit(c_strInfo);
		QMessageBox::warning(this, dlgTitle, strInfo, QMessageBox::Ok | QMessageBox::Default);
		return false;
	}
	return true;
}

///执行打包
bool Package_v4::Fun_StartPackage()
{
	///创建第二级目录
	Create_Dir(m_qDirPath2);
	Create_Dir(m_qDirPath3);
	Create_Dir(m_qDirPath4);
	Create_Dir(m_qDirPath5);
	Create_Dir(m_qDirPath6);

	///META-INF文件操作
	Replace_File(m_qDirPath7_From, m_qDirPath7_To);

	///minio_assistant_{2}文件操作
	Copy_Dir(m_qDirPath8_From, m_qDirPath8_To, true);
	Copy_File(m_qDirPath9_From, m_qDirPath9_To, true);
	Copy_File(m_qDirPath10_From, m_qDirPath10_To, true);
	Copy_File(m_qDirPath11_From, m_qDirPath11_To, true);
	Replace_File(m_qDirPath12_From, m_qDirPath12_To);

	///script文件操作
	Replace_File(m_qDirPath13_From, m_qDirPath13_To);

	///xres-rms文件操作
	Create_Dir(m_qDirPath14);
	Create_Dir(m_qDirPath15);
	Create_Dir(m_qDirPath16);
	Replace_File(m_qDirPath17_From, m_qDirPath17_To);
	Replace_File(m_qDirPath18_From, m_qDirPath18_To);
	Replace_File(m_qDirPath19_From, m_qDirPath19_To);
	Replace_File(m_qDirPath20_From, m_qDirPath20_To);

	///xres-trigger文件操作
	Create_Dir(m_qDirPath21);
	Create_Dir(m_qDirPath22);
	Create_Dir(m_qDirPath23);
	Create_Dir(m_qDirPath24);
	Replace_File(m_qDirPath25_From, m_qDirPath25_To);

	if (m_qsTrue == m_qIsUniversal)
	{
		///压缩解压jar包
		Fun_Do7za(m_str7za_e);
		Replace_File(m_qDirPath26, m_qDirPath26);
		Fun_Do7za(m_str7za_a);
		Copy_File(m_qDirPath27_From, m_qDirPath27_To, true);
		DeleteFileOrDir(m_qDirPath26);
		DeleteFileOrDir(m_qDirPath27_From);
	}
	else if (m_qsFalse == m_qIsUniversal)
	{
		///替换导入jar包
		Copy_File(m_qsSelectFilepath, m_qDirPath29, true);
	}

	///生成最终压缩包
	Fun_Do7za(m_str7za_aall);
	Copy_File(m_qDirPath28_From, m_qDirPath28_To, true);
	
	///删除无用文件和文件夹
	DeleteFileOrDir(m_qDirPath2);
	DeleteFileOrDir(m_qDirPath3);
	DeleteFileOrDir(m_qDirPath4);
	DeleteFileOrDir(m_qDirPath5);
	DeleteFileOrDir(m_qDirPath6);
	DeleteFileOrDir(m_qDirPath28_From);
	return true;
}

///打包成功提示
void Package_v4::Fun_PackCompleteTip()
{
	const char* c_dlgTitle = "完成";
	QString dlgTitle = QString::fromLocal8Bit(c_dlgTitle);
	const char* c_strInfo = "设备资源包已成功生成";
	QString strInfo = QString::fromLocal8Bit(c_strInfo);
	QMessageBox::information(this, dlgTitle, strInfo, QMessageBox::Ok | QMessageBox::Default);
}

