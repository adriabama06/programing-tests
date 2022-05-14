package es.protector.config;

import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.configuration.file.YamlConfiguration;
import org.bukkit.plugin.java.JavaPlugin;

import java.io.File;
import java.io.IOException;

public class Config {
    private static FileConfiguration Config;
    private static FileConfiguration Messages;
    private static FileConfiguration Protect;


    public static FileConfiguration GetConfig() {
        return Config;
    }
    public static void SaveConfig(JavaPlugin plugin) {
        plugin.saveConfig();
        return;
    }
    public static void ReloadConfig(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "config.yml");
        if(!datFile.exists()) {
            plugin.getConfig().options().copyDefaults(true);
            plugin.saveConfig();
        }
        plugin.reloadConfig();
        Config = plugin.getConfig();
        return;
    }


    public static FileConfiguration GetMessages() {
        return Messages;
    }
    public static boolean SaveMessages(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "messages.yml");
        if(!datFile.exists()) {
            ReloadMessages(plugin);
            return false;
        }
        try {
            Messages.save(datFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return true;
    }
    public static boolean ReloadMessages(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "messages.yml");
        if(!datFile.exists()) {
            datFile.getParentFile().mkdirs();
            plugin.saveResource("messages.yml", false);
        }
        FileConfiguration dat = YamlConfiguration.loadConfiguration(datFile);
        Messages = dat;
        return true;
    }


    public static FileConfiguration GetProtect() {
        return Protect;
    }
    public static boolean SaveProtect(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "protect.yml");
        if(!datFile.exists()) {
            ReloadMessages(plugin);
            return false;
        }
        try {
            Protect.save(datFile);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return true;
    }
    public static boolean ReloadProtect(JavaPlugin plugin) {
        File datFile = new File(plugin.getDataFolder(), "protect.yml");
        if(!datFile.exists()) {
            datFile.getParentFile().mkdirs();
            plugin.saveResource("protect.yml", false);
        }
        FileConfiguration dat = YamlConfiguration.loadConfiguration(datFile);
        Protect = dat;
        return true;
    }
}
