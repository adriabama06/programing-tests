package es.protector;

import es.protector.cmds.protector;
import es.protector.config.Config;
import es.protector.events.*;
import org.bukkit.Bukkit;
import org.bukkit.plugin.java.JavaPlugin;

public class Main extends JavaPlugin {
    @Override
    public void onEnable() {
        Bukkit.getConsoleSender().sendMessage(Util.color("&e&l[Protector] &astarted v0.0.1"));

        new protector(this);

        Config.ReloadProtect(this);
        Config.ReloadConfig(this);
        Config.ReloadMessages(this);

        new AntiBuild(this);
        new AntiFood(this);
        new AntiHeal(this);
    }

    @Override
    public void onDisable() {
        Bukkit.getConsoleSender().sendMessage(Util.color("&e&l[Protector] &cdisabled... v0.0.1"));
    }
}