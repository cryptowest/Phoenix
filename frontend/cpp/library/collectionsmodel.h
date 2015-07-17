#ifndef COLLECTIONSMODEL_H
#define COLLECTIONSMODEL_H

#include "libraryinternaldatabase.h"

#include <QSqlTableModel>
#include <QHash>
#include <QVariantMap>

namespace Library {

    class CollectionsModel : public QSqlTableModel {
            Q_OBJECT
        public:

            using QSqlTableModel::setFilter;

            explicit CollectionsModel( QObject *parent = 0 );

            enum CollectionRoles {
                CollectionIDRole = Qt::UserRole + 1,
                CollectionNameRole,
            };

            Q_ENUMS( CollectionRoles );

            virtual QHash<int, QByteArray> roleNames() const override;
            virtual bool select() override;
            virtual QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const override;
            virtual void sort( int column, Qt::SortOrder order ) override;

        public slots:
            void append( const QVariantMap dict );
            void setFilter( const CollectionRoles role, const QVariant id );

        private:
            explicit CollectionsModel( LibraryInternalDatabase &db, QObject *parent = 0 );

            explicit CollectionsModel( LibraryInternalDatabase *db, QObject *parent = 0 );

            LibraryInternalDatabase *mLibraryDatabase;
            QHash<int, QByteArray> mRoleNames;
            QVariantList params;
            QHash<CollectionRoles, QVariant> filterParameterMap;


    };
}

#endif // COLLECTIONSMODEL_H