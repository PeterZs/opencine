#ifndef BACKUPPRESENTER_H
#define BACKUPPRESENTER_H

#include <vector>
#include <functional>

#include <QFileSystemModel>
#include <QObject>
#include <QStringListModel>
#include <QItemSelection>

#include "../Interfaces/IBackupView.h"

class IBackupPresenter : public QObject
{
	Q_OBJECT

public:
	//virtual void RefreshDriveList() = 0;
	//virtual void SelectDrive(std::string drivePath) = 0;

	//virtual void StartTransfer() = 0;

signals:
	//void DriveListChanged(std::vector<DriveInfo> driveList);
	//void DriveSelectionChanged(std::vector<std::string> driveList);
};

class BackupPresenter : public IBackupPresenter
{
	Q_OBJECT
	
	IBackupView* _view;
	IDriveManager* _driveManager;

	std::vector<DriveInfo> _driveList;

	void SetupSignals() const;

	void StartTransfer() const;

	//signals:
		//void StartTransferSig(std::string drivePath);

	private slots:
	void DriveListChanged(std::vector<DriveInfo> driveList);
	void DriveSelectionChanged(int driveIndex);
	void AddDestination() const;
	void FolderSelectionChanged(QString folderPath) const;

public:
	explicit BackupPresenter(IBackupView& view);
};

#endif // BACKUPPRESENTER_H
