```
$ git clone https://github.com/JackMaguire/CLIProteinViewer.git
Cloning into 'CLIProteinViewer'...
remote: Enumerating objects: 46, done.
remote: Counting objects: 100% (46/46), done.
remote: Compressing objects: 100% (41/41), done.
remote: Total 586 (delta 23), reused 13 (delta 4), pack-reused 540
Receiving objects: 100% (586/586), 2.99 MiB | 0 bytes/s, done.
Resolving deltas: 100% (297/297), done.
$ cd CLIProteinViewer
$ bash just_install_everything_please.sh
Installation was a success. To use this tool in your current session, run 'source /nas/longleaf/home/jackmag/.bashrc'. The CLIProteinViewer will be available for all future session.
$ source /nas/longleaf/home/jackmag/.bashrc
$ ./set_CLIPV_params #I made my screen's text very small before running this. On mac, this is done with command and the minus sign
Creating file: /nas/longleaf/home/jackmag/.clipv.settings
Fitting parameters for screen size: 183 x 678
183 x 678
```

Omitting the visual output of the program itself. I ended up hitting the left arrow key once and then hit `q`

```
$ cd /path/to/my/pdb/files
$ CLIProteinViewer my_protein.pdb #can pass multiple pdb files
```
