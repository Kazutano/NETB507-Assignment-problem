void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "",
                                                    tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    agents.clear();
    tasks.clear();
    costs.clear();

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(",");

        QString agent = data[0];
        QString task = data[1];
        int cost = data[2].toInt();

        if (!agents.contains(agent))
            agents.append(agent);
        if (!tasks.contains(task))
            tasks.append(task);

        costs[agents.indexOf(agent)][tasks.indexOf(task)] = cost;
    }

    file.close();

    updateGraph();
}
