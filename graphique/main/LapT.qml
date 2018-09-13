import QtQuick 2.3
import QtQuick.Controls 1.4

Column
{
  property string a
  property string b

  Text{
    text: a
  }

  Text{
    text:"+"+b
  }

}