#ifndef UPDATESEARCHER_H
#define UPDATESEARCHER_H

#include <QString>
#include <QStringList>

#include "..\wpmcpp\job.h"
#include "..\wpmcpp\packageversion.h"
#include "..\wpmcpp\repository.h"

class UpdateSearcher
{
public:
    /** type of the download URL */
    enum DownloadType {
        /** the URL is stable */
        DT_STABLE,

        /**
         * the URL is unstable. The file should be uploaded to
         * npackd.googlecode.com
         */
        DT_GOOGLECODE,

        /**
         * the URL is unstable. The file should be uploaded to
         * www.dropbox.com
         */
        DT_DROPBOX,

        /**
         * the URL is unstable. The file should be uploaded to
         * www.dropbox.com
         */
        DT_SOURCEFORGE
    };
private:
    void setDownload(Job* job, PackageVersion* pv, const QString& download);

    QString findTextInPage(Job* job, const QString& url,
            const QString& regex);
    QStringList findTextsInPage(Job* job, const QString& url,
            const QString& regex);

    /**
     * @param versionRE regular expression for the version number. Only valid
     *     version numbers or valid version numbers with a one-letter suffix
     *     are allowed. Examples: "1.2", "1.2.3b"
     */
    PackageVersion* findUpdate(Job* job, const QString& package,
            const QString& versionPage,
            const QString& versionRE, QString* realVersion=0,
            bool searchForMaxVersion=false);

    PackageVersion* findGTKPlusBundleUpdates(Job* job);
    PackageVersion* findH2Updates(Job* job);
    PackageVersion* findImgBurnUpdates(Job* job);
    PackageVersion* findIrfanViewUpdates(Job* job);
    PackageVersion* findAC3FilterUpdates(Job* job);
    PackageVersion* findAdobeReaderUpdates(Job* job);
    PackageVersion* findXULRunnerUpdates(Job* job);    
    PackageVersion* findClementineUpdates(Job* job);
    PackageVersion* findAdvancedInstallerFreewareUpdates(Job* job,
            Repository* templ);
    PackageVersion* findAria2Updates(Job* job,
            Repository* templ);

    /**
     * SHA1 will not be added if it is not in the template.
     *
     * @param download if not empty, contains the URL for the file to download
     */
    PackageVersion* findUpdatesSimple(Job* job, const QString& package,
            const QString& versionPage, const QString& versionRE,
            const QString& downloadTemplate,
            Repository* templ,
            DownloadType dt = DT_STABLE,
            bool searchForMaxVersion = false);
public:
    /**
     * -
     */
    UpdateSearcher();

    /**
     * Searches for updates.
     *
     * @param job Job description
     */
    void findUpdates(Job* job);
};

#endif // UPDATESEARCHER_H