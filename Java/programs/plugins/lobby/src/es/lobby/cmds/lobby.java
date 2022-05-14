package es.lobby.cmds;

import es.lobby.Main;
import es.lobby.Util;
import es.lobby.config.Config;
import es.lobby.items.ItemMannager;
import es.lobby.menus.servers;
import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.command.Command;
import org.bukkit.command.CommandExecutor;
import org.bukkit.command.CommandSender;
import org.bukkit.configuration.file.FileConfiguration;
import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerTeleportEvent;

import java.util.List;

public class lobby implements CommandExecutor {
    // Create local variable
    private Main plugin;

    // Connect to main
    public lobby(Main plugin) {
        this.plugin = plugin;
        // Register the command
        plugin.getCommand("lobby").setExecutor(this);
    }

    @Override
    public boolean onCommand(CommandSender sender, Command cmd, String label, String[] args) {
        if(sender instanceof Player) {
            if(!((Player) sender).getPlayer().hasPermission("lobby.cmd.lobby")) {
                return true;
            }
        }
        /*
        Player p = (Player) sender;
        ((Player) sender).getPlayer();
        */
        if(args.length >= 1) {
            if(args[0].equalsIgnoreCase("spawn")) {
                if(!(sender instanceof Player)) {
                    sender.sendMessage(Util.color(Config.GetMessages().getString("consola-no-permitida").replace("%cmd%", "/lobby spawn")));
                    return true;
                }
                Player p = (Player) sender;
                String world = Config.GetLocations().getString("lobby.world");
                if(world == null) {
                    p.sendMessage(Util.color(Config.GetMessages().getString("lobby.no-hay-spawn")));
                    return true;
                }
                FileConfiguration locs = Config.GetLocations();
                double x = locs.getDouble("lobby.x");
                double y = locs.getDouble("lobby.y");
                double z = locs.getDouble("lobby.z");
                float yaw = Float.valueOf(locs.getString("lobby.yaw"));
                float pitch = Float.valueOf(locs.getString("lobby.pitch"));
                p.teleport(new Location(Bukkit.getWorld(world), x, y, z, yaw, pitch), PlayerTeleportEvent.TeleportCause.PLUGIN);
                p.sendMessage(Util.color(Config.GetMessages().getString("lobby.enviando")));
                return true;
            }
            if(args[0].equalsIgnoreCase("setspawn")) {
                if (!(sender instanceof Player)) {
                    sender.sendMessage(Util.color(Config.GetMessages().getString("consola-no-permitida").replace("%cmd%", "/lobby setspawn")));
                    return true;
                }
                Player p = (Player) sender;
                Location loc = p.getLocation();
                FileConfiguration locs = Config.GetLocations();
                locs.set("lobby.world", loc.getWorld().getName());
                locs.set("lobby.x", loc.getX());
                locs.set("lobby.y", loc.getY());
                locs.set("lobby.z", loc.getZ());
                locs.set("lobby.yaw", loc.getYaw());
                locs.set("lobby.pitch", loc.getPitch());
                Config.SaveLocations(plugin);
                p.sendMessage(Util.color(Config.GetMessages().getString("lobby.set-spawn")
                        .replace("%x%", String.valueOf(loc.getX()))
                        .replace("%y%", String.valueOf(loc.getY()))
                        .replace("%z%", String.valueOf(loc.getZ()))));
                return true;
            }
            if(args[0].equalsIgnoreCase("servers")) {
                if (!(sender instanceof Player)) {
                    sender.sendMessage(Util.color(Config.GetMessages().getString("consola-no-permitida").replace("%cmd%", "/lobby servers")));
                    return true;
                }
                servers.openInv(((Player) sender).getPlayer());
                return true;
            }
            if(args[0].equalsIgnoreCase("reload")) {
                Config.ReloadConfig(plugin);
                Config.ReloadMessages(plugin);
                Config.ReloadLocations(plugin);
                Config.ReloadItems(plugin);
                Config.ReloadMenus(plugin);
                servers.initalize();
                ItemMannager.initalize();
                sender.sendMessage(Util.color("&a&lPlugin recargado!"));
                return true;
            }
        } else {
            List<String> help = Config.GetMessages().getStringList("help");
            for(String h : help) {
                sender.sendMessage(Util.color(h));
            }
            return true;
        }
        return true; // return false = on command end at the console show how use defined in plugin.yml
    }
}
