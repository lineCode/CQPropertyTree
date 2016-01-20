#ifndef CQPropertyDelegate_H
#define CQPropertyDelegate_H

#include <QItemDelegate>
#include <CAngle.h>

class CQPropertyTree;
class QTreeWidgetItem;

// Tree Widget Item Delegate class to handle custom editing of tree widget items
class CQPropertyDelegate : public QItemDelegate {
  Q_OBJECT

 public:
  CQPropertyDelegate(CQPropertyTree *tree);

  // Override to create editor
  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;

  // Override to get content from editor
  void setEditorData(QWidget *editor, const QModelIndex &index) const;

  void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                            const QModelIndex &index) const;

  void paint(QPainter *painter, const QStyleOptionViewItem &option,
             const QModelIndex &index) const;

  QTreeWidgetItem *getModelItem(const QModelIndex &index) const;

  QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;

  QWidget *createEdit(QWidget *parent, const QString &text) const;

  void drawCheck(QPainter *painter, const QStyleOptionViewItem &option,
                 bool checked, const QModelIndex &index) const;
  void drawColor(QPainter *painter, const QStyleOptionViewItem &option,
                 const QColor &c, const QModelIndex &index) const;
  void drawFont (QPainter *painter, const QStyleOptionViewItem &option,
                 const QFont &f, const QModelIndex &index) const;
  void drawPoint(QPainter *painter, const QStyleOptionViewItem &option,
                 const QPointF &p, const QModelIndex &index) const;
  void drawAngle(QPainter *painter, const QStyleOptionViewItem &option,
                 const CAngle &a, const QModelIndex &index) const;
  void drawString(QPainter *painter, const QStyleOptionViewItem &option,
                  const QString &str, const QModelIndex &index) const;

 private:
  CQPropertyTree *tree_;
};

#endif
