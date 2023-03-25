# 42_minitalk

Bu projede pipex, signal gibi IPC(Inter-Procces Communication) yollarından sinyalleri kullanarak client processinden server processine string yolladım.

Önce server çalıştırılır, server kendi pid(process id) değerini terminale bastırır. Daha sonra server'ın pid değerini ve yollamak istenilen stringi cliente argüman olarak vererek client çalıştılır.

![minitalk](https://user-images.githubusercontent.com/89595806/227714025-8fa58296-bd22-4a11-8fcf-db45a21cdf63.png)
