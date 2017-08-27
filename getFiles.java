public class FileGetter {
	
	public static ArrayList<File> getFiles( File folder ) {
                ArrayList<File> files = new ArrayList<>();
                getFiles( folder, files );
                return files;
        }

        private static void getFiles( File folder, ArrayList<File> files ) {
                if( !folder.isDirectory() ) {
                        files.add(folder);
                }
                else {
                        File[] localFiles = folder.listFiles();

                        for( File f : localFiles ) {
                                getFiles( f, files );
                        }
                }
        }


}
